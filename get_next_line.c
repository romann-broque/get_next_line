/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:10:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/05 11:16:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;


char	*dup_until(char *str, const char c)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		++i;
	dup = (char *)malloc((i + 1) * sizeof(char));	
	if (dup != NULL)
		ft_strncpy(dup, str, i);
	return (dup);
}

t_line_status	fill_line_from_rest(char **line, char rest[BUFFER_SIZE + 1])
{
	if (ft_strchr(rest, '\n') != NULL)
	{
		*line = dup_until(rest, '\n');
		return (VALID_LINE);
	}
	else
		return (INVALID_LINE);
}

t_line_status	fill_line_from_file(char **line,
								char rest[BUFFER_SIZE + 1], const int fd)
{
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		rest = ft_strchr(buffer, '\n');
		if (rest == NULL)
			*line = ft_strjoin(*line, buffer);
		else
			break ;
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	return (VALID_LINE);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1] = EMPTY_STRING;
	char		*line;

	line = NULL;
	if (fill_line_from_rest(&line, rest) == INVALID_LINE)
		fill_line_from_file(&line, rest, fd);
	return (line);
}
