/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nismayil <nismayil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:19:35 by nismayil          #+#    #+#             */
/*   Updated: 2024/12/16 01:22:40 by nismayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int count_line_chars(char *str)
{
	int count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	if (str[count] == '\n')
		count++;
	return (count);
}

char *single_line(char *buffer)
{
	char *line;
	int count;
	int i;

	if (!buffer)
		return (NULL);
	count = count_line_chars(buffer);
	line = malloc((count + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < count)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t len;
	char *str;
	char *start;

	if (!s1 && !s2)
		return (NULL);
	len = count_line_chars(s1) + count_line_chars(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	if (s1)
		while (*s1)
			*str++ = *s1++;
	if (s2)
		while (*s2)
			*str++ = *s2++;
	*str = '\0';
	return (start);
}

void free_line(char *some_line)
{
	if (some_line)
		free(some_line);
	return;
}
