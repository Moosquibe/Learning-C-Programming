#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];

void dump(struct part *inventory, int *num_parts, char *filename);
void restore(struct part *inventory, int *num_parts, char *filename);
int compare_parts(const void *p, const void *q);

int main(int argc, char *argv[])
{
  struct part inventory1[MAX_PARTS], inventory2[MAX_PARTS], inventory[MAX_PARTS];
  int num_parts1, num_parts2;

  if (argc != 4) {
    fprintf(stderr, "Usage: merge_inventory <input1> <input2> <output>");
    exit(EXIT_FAILURE);
  }
  
  restore(inventory1, &num_parts1, argv[1]);
  restore(inventory2, &num_parts2, argv[2]);

  // Sort them
  qsort(inventory1, num_parts1, sizeof(struct part), compare_parts);
  qsort(inventory2, num_parts2, sizeof(struct part), compare_parts);

  // Merge them like in mergesort
  int i = 0, j = 0, k = 0;
  
  while (i < num_parts1 || j < num_parts2) {
    if (k >= MAX_PARTS) {
      fprintf(stderr, "Resulting inventory is too large.\n");
      exit(EXIT_FAILURE);
    }
    if (j >= num_parts2 || inventory1[i].number < inventory2[j].number) {
      inventory[k].number = inventory1[i].number;
      strcpy(inventory[k].name, inventory1[i].name);
      inventory[k].on_hand = inventory1[i].on_hand;
      i++;
    } else if (i >= num_parts1 || inventory1[i].number > inventory2[j].number) {
      inventory[k].number = inventory2[j].number;
      strcpy(inventory[k].name, inventory2[j].name);
      inventory[k].on_hand = inventory2[j].on_hand;
      j++;
    } else {
      if (strcmp(inventory1[i].name, inventory2[j].name) != 0) {
        fprintf(stderr, "Inconsistent part names for part number %d", inventory1[i].number);
        exit(EXIT_FAILURE);
      }
      inventory[k].number = inventory1[i].number;
      strcpy(inventory[k].name, inventory1[i].name);
      inventory[k].on_hand = inventory1[i].on_hand + inventory2[j].on_hand;
      i++; j++;
    }
    k++;
  }
    
  dump(inventory, &k, argv[3]);
  return 0;
}

void dump(struct part *inventory, int *num_parts, char *filename)
{
  FILE *fp;
  int parts_dumped;

  if ((fp = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "Cannot open %s for dumping\n", filename);
    return;
  } 

  parts_dumped = fwrite(inventory, sizeof(struct part), *num_parts, fp);

  if (parts_dumped < *num_parts) {
    fprintf(stderr, "Couldn't save all parts.");
  }  

  fclose(fp);
}

void restore(struct part *inventory, int *num_parts, char *filename)
{
  FILE *fp;

  if ((fp = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "Cannot open %s to load from\n", filename);
    return;
  }

  *num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
}

int compare_parts(const void *p, const void *q) {
  const struct part *p1 = p;
  const struct part *q1 = q;

  if (p1->number < q1->number)
    return -1;
  else if (p1->number == q1->number)
    return 0;
  else
    return 1;
}