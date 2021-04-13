#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int max_int(int first, ...) {
    va_list ap;
    int i, current, largest = first;

    va_start(ap, first);

    while ((current = va_arg(ap, int)) != 0) {
      if (current > largest)
        largest = current;
    }

    va_end(ap);
    return largest;
}

int my_printf(char *format, ...) {
  va_list ap;
  bool prev_percent = false;
  int iparam, count = 0;
  char *strparam;

  va_start(ap, format);
  
  while(*format) {
    if (*format == '%') {
      prev_percent = true;
    } else {
      if (prev_percent) {
        if (*format == 'd') {
          iparam = va_arg(ap, int);
          if (iparam < 0) {
              putchar('-');
              iparam = - iparam;
              count++;
          }
          for (int length = (int) log10(iparam); length >= 0; length--) {
            putchar('0' + (iparam / (int) pow(10, length)) % 10);
            count++;
          }
        } else if (*format == 's') {
          strparam = va_arg(ap, char*);
          while (*strparam) {
            putchar(*strparam);
            count++;
            strparam++;
          }
        }
        prev_percent = false;
      } else {
          putchar(*format);
          count++;
      }
    }
    format++;
  }

  va_end(ap);
  return count;
}

char *vstrcat(const char *first, ...) {
  va_list ap;
  int total_length;
  char *current = (char*) first, *result, *p;

  va_start(ap, first);
  do {
    total_length += strlen(current);
  }  while((current = va_arg(ap, char*)) != NULL);

  if ((result = malloc(total_length + 1)) == NULL)
    return NULL;

  current = (char*) first;
  va_start(ap, first);
  p = result;
  do {
    strncpy(p, current, strlen(current));
    p += strlen(current);
  }  while((current = va_arg(ap, char*)) != NULL);
  *p = '\0';

  va_end(ap);
  return result;  
}

void display(int n, ...) {
   va_list ap;
   va_start(ap, n);
   char *current;
   
   for(int i = 0; i < n; i++) {
     current = va_arg(ap, char*);
     printf("%s", current);
     if (i < n - 1)
       putchar(' ');
   }
   va_end(ap);
}

char *max_pair(int num_pairs, ...) {
    va_list ap;
    int curr_num, max_num = INT_MIN;
    char *curr_str, *max_str;

    va_start(ap, num_pairs);
    for(int i = 0; i < num_pairs; i++) {
      curr_num = va_arg(ap, int);
      curr_str = va_arg(ap, char*);

      if (curr_num >= max_num) {
          max_num = curr_num;
          max_str = curr_str;
      }
    }
    va_end(ap);
    return max_str;
}

int main(int argc, char* argv[]) {
    assert(max_int(3, 4, -5, 0) == 4);
    my_printf("The number 254 is %d\n", 254);
    my_printf("The string 'Bena bela' is %s\n", "Bena bela");
    display(4, "Special", "Agent", "Dale", "Cooper");

    printf("\n");

    printf("%s", vstrcat("Bena", "Bela", "maszik", "haza", "\n", NULL));

    assert(strcmp(max_pair(5, 
                           180, "Seinfeld", 
                           180, "I love lucy", 
                           39, "The Honeymooners", 
                           210, "All in the family",
                           86, "The Sopranos"), 
                  "All in the family") == 0);
}