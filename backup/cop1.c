/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nismayil <nismayil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:18:24 by nismayil          #+#    #+#             */
/*   Updated: 2024/12/15 15:07:10 by nismayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void free_and_nullify(char *some_line)
{
    free_line(some_line);
    some_line = NULL;
    return;
}

void create_line(char *str, char **final_line)
{
    char *new_line;
    char *check_line;

    new_line = single_line(str);
    if (!new_line)
    {
        free_line(*final_line);
        *final_line = NULL;
        return;
    }
    check_line = ft_strjoin(*final_line, new_line);
    free_line(new_line);
    free_line(*final_line);
    if (!check_line)
    {
        *final_line = NULL;
        return;
    }
    *final_line = ft_strdup(check_line);
    free_line(check_line);
    if (!(*final_line))
    {
        *final_line = NULL;
        return;
    }
    return;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    static int index = 0;
    int stop;
    int bytes_read;
    char *final_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    final_line = NULL;
    stop = 0;
    bytes_read = 0;
    while (stop != 1)
    {
        if (!buf[index])
        {
            bytes_read = read(fd, buf, BUFFER_SIZE);
            if (bytes_read == 0)
                break;
            if (bytes_read == -1)
            {
                // free_line(final_line);
                // final_line = NULL;
                free_and_nullify(final_line);
                return (NULL);
            }
            buf[bytes_read] = '\0';
            index = 0;
        }
        create_line(&buf[index], &final_line);
        if (!final_line)
        {
            free_line(final_line);
            // final_line = NULL;
            // free_and_nullify(final_line);
            break;
        }
        index += count_line_chars(&buf[index]) - 1;
        if (buf[index] == '\n')
        {
            index++;
            break;
        }
        index++;
    }
    return (final_line);
}
