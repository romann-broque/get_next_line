/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:10:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/06 12:13:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;

t_line_status	fill_line_from_rest(char **line, char **rest)
{
	size_t pos;

	if (*rest != NULL)
	{
		if (ft_strchr(*rest, '\n') != NULL)
		{
			pos = ft_strlenchr(*rest, '\n');
			*line = ft_strndup(*rest, pos);
			*rest = ft_strchr(*rest, '\n') + 1;
			return (VALID_LINE);
		}
		else
		{
			if (**rest != '\0')
				*line = ft_strdup(*rest);
		}
	}
	return (INVALID_LINE);
}

t_line_status	fill_line_from_file(char **line,
		char **rest, const int fd)
{
	size_t	pos;
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		pos = ft_strlenchr(buffer, '\n');
		if (pos < BUFFER_SIZE)
			*rest = ft_strndup(buffer + pos + 1, BUFFER_SIZE - pos - 1);
		else
			*rest = NULL;
		*line = ft_strjoin(*line, ft_strndup(buffer, pos));
		if (*rest != NULL)
			break ;
	}
	return (VALID_LINE);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;

	line = NULL;
	if (fill_line_from_rest(&line, &rest) == INVALID_LINE)
		fill_line_from_file(&line, &rest, fd);
	return (line);
}
