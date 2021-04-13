#include <stdio.h>
#include <assert.h>
#include <string.h>

// Problem 16
int sum(int (*f)(int), int start, int end) {
    int total = 0;
    for (int i = start; i <= end; i++)
      total += (*f)(i);

    return total;
}

int test_func(int i) {
    return i;
}

// Problem 19
void new_cmd(void) {
    printf("new");
}
void open_cmd(void) {
    printf("open");
}
void close_cmd(void) {
    printf("close");
}
void close_all_cmd(void) {
    printf("close_all");
}
void save_cmd(void) {
    printf("save");
}
void save_as_cmd(void) {
    printf("save as");
}
void save_all_cmd(void) {
    printf("save all");
}
void print_cmd(void) {
    printf("print");
}
void exit_cmd(void) {
    printf("exit");
}

struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] = 
  {{"new",        new_cmd},
   {"open",       open_cmd},
   {"close",      close_cmd},
   {"close all",  close_all_cmd},
   {"save",       save_cmd},
   {"save as",    save_as_cmd},
   {"save all",   save_all_cmd},
   {"print",      print_cmd},
   {"exit",       exit_cmd}
  };

void dispatch(char *cmd_str) {
    for (int i = 0; i < 9; i++)
      if (strcmp(cmd_str, file_cmd[i].cmd_name) == 0) {
          (*file_cmd[i].cmd_pointer)();
      }
}

int main(void) {
    assert(sum(test_func, 1, 3) == 6);
    dispatch("save all");
    printf("\n");
    return 0;
}