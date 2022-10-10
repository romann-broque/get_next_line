/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:10:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/10 11:11:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnjoin(char const *s1, char const *s2, const size_t n)
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
	if (len2 > n)
		len2 = n;
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		ft_strncpy(new, (char *)s1, len1);
		ft_strncpy(new + len1, (char *)s2, len2);
	}
	return (new);
}

static void	ft_strnadd(char **str, char *add, const size_t n)
{
	char	*new;

	new = ft_strnjoin(*str, add, n);
	free(*str);
	*str = new;
}

static t_line_status	get_line_from_buff(char **line, char *buffer)
{
	size_t	pos;

	pos = ft_strlenchr(buffer, '\n');
	if (buffer[pos] == '\n')
	{
		ft_strnadd(line, buffer, pos + 1);
		ft_strncpy(buffer, buffer + pos + 1, BUFFER_SIZE);
		return (VALID_LINE);
	}
	else if (*buffer != '\0')
		ft_strnadd(line, buffer, BUFFER_SIZE);
	return (INVALID_LINE);
}

static t_line_status	fill_line_from_file(char **line,
		char *rest, const int fd)
{
	ssize_t	read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		if (get_line_from_buff(line, buffer) == VALID_LINE)
		{
			ft_strncpy(rest, buffer, read_bytes);
			break ;
		}
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes == -1)
		return (INVALID_LINE);
	return (VALID_LINE);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1] = EMPTY_STRING;
	char		*line;

	line = NULL;
	if (fd > -1 && fd < OPEN_MAX)
	{
		if (get_line_from_buff(&line, rest) == INVALID_LINE)
			fill_line_from_file(&line, rest, fd);
	}
	return (line);
}
