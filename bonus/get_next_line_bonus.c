/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:34:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/10 14:58:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_line_status	get_line_from_buff(char **line, char *buffer)
{
	size_t	index;

	index = index_of(buffer, '\n');
	if (*buffer != '\0')
	{
		*line = strnjoin(*line, buffer, index + 1);
		if (buffer[index] == '\n') 
		{
			ft_strncpy(buffer, buffer + index + 1, BUFFER_SIZE);
			return (VALID_LINE);
		}
	}
	return (INVALID_LINE);
}

static t_line_status	fill_line_from_file(char **line,
											char *rest, const int fd)
{
	ssize_t	read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0 && get_line_from_buff(line, buffer) == INVALID_LINE)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes == -1)
		return (INVALID_LINE);
	ft_strncpy(rest, buffer, read_bytes);
	return (VALID_LINE);
}

char	*get_next_line(int fd)
{
	static char		rest[(BUFFER_SIZE + 1) * OPEN_MAX] = EMPTY_STRING;
	const size_t	offset = fd * (BUFFER_SIZE + 1);
	char			*line;

	line = NULL;
	if (fd > -1 && fd < OPEN_MAX)
	{
		if (get_line_from_buff(&line, rest + offset) == INVALID_LINE)
			fill_line_from_file(&line, rest + offset, fd);
	}
	return (line);
}
