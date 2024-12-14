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
char *single_line(char *buffer);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *s1);

void *memset_null(void *b, size_t len);

#endif
