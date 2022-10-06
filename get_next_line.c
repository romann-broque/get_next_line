/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:10:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/06 16:28:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;

void	ft_stradd(char **str, char *add)
{
	char	*new;

	new = ft_strjoin(*str, add);
	free(*str);
	free(add);
	*str = new;
}

t_line_status	fill_line_from_rest(char **line, char *rest)
{
	size_t pos;

	if (ft_strchr(rest, '\n') != NULL)
	{
		pos = ft_strlenchr(rest, '\n');
		*line = ft_strndup(rest, pos + 1);
		ft_strcpy(rest, ft_strchr(rest, '\n') + 1);
		return (VALID_LINE);
	}
	else if (*rest != '\0')
		*line = ft_strdup(rest);
	return (INVALID_LINE);
}

t_line_status	fill_line_from_file(char **line,
		char *rest, const int fd)
{
	ssize_t	read_bytes;
	ssize_t	pos;
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		pos = ft_strlenchr(buffer, '\n');
		ft_stradd(line, ft_strndup(buffer, pos + 1));
		if (pos < read_bytes)
		{
			ft_strncpy(rest, buffer + pos + 1, read_bytes - pos - 1);
			break ;
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (VALID_LINE);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE] = EMPTY_STRING;
	char		*line;

	line = NULL;
	if (fill_line_from_rest(&line, rest) == INVALID_LINE)
		fill_line_from_file(&line, rest, fd);
	return (line);
}
