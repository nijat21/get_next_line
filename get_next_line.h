#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd);
int count_line_chars(char *str);
char *single_line(char *buffer, int is_end);

#endif
