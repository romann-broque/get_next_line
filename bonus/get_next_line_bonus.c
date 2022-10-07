/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:34:02 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/07 18:34:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (s1 == NULL)
		s1 = EMPTY_STRING;
	if (s2 == NULL)
		s2 = EMPTY_STRING;
	len1 = ft_strlenchr(s1, '\0');
	len2 = ft_strlenchr(s2, '\0');
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		ft_strncpy(new, (char *)s1, len1);
		ft_strncpy(new + len1, (char *)s2, len2);
	}
	return (new);
}

static void	ft_stradd(char **str, char *add)
{
	char	*new;

	new = ft_strjoin(*str, add);
	free(*str);
	free(add);
	*str = new;
}

static t_line_status	fill_line_from_rest(char **line, char *rest)
{
	size_t	pos;

	if (ft_strchr(rest, '\n') != NULL)
	{
		pos = ft_strlenchr(rest, '\n');
		*line = ft_strndup(rest, pos + 1);
		ft_strncpy(rest, ft_strchr(rest, '\n') + 1, BUFFER_SIZE);
		return (VALID_LINE);
	}
	else if (*rest != '\0')
		*line = ft_strndup(rest, BUFFER_SIZE);
	return (INVALID_LINE);
}

static t_line_status	fill_line_from_file(char **line,
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
			ft_strncpy(rest, buffer + pos + 1, read_bytes - pos);
			break ;
		}
		ft_bzero(buffer, BUFFER_SIZE + 1);
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
