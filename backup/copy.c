/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nismayil <nismayil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:18:24 by nismayil          #+#    #+#             */
/*   Updated: 2024/12/14 14:28:24 by nismayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	index = 0;
	int			stop;
	int			bytes_read;
	char		*new_line;
	char		*check_line;
	char		*final_line;

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
				break ;
			if (bytes_read == -1)
			{
				free_line(final_line);
				return (NULL);
			}
			buf[bytes_read] = '\0';
			index = 0;
		}
		else
		{
			new_line = single_line(&buf[index]);
			if (!new_line)
			{
				free_line(final_line);
				break ;
			}
			check_line = ft_strjoin(final_line, new_line);
			free_line(final_line);
			free_line(new_line);
			if (!check_line)
				break ;
			final_line = ft_strdup(check_line);
			free_line(check_line);
			if (!final_line)
				break ;
			index += count_line_chars(&buf[index]) - 1;
			if (buf[index] == '\n')
			{
				index++;
				break ;
			}
			index++;
		}
	}
	return (final_line);
}
