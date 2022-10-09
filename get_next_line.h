/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:09:26 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/09 15:43:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define OPEN_MAX 256
# define EMPTY_STRING ""

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;

char	*ft_strncpy(char *dest, char *src, size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *ptr, size_t size);
char	*ft_strndup(const char *str, const size_t size);
size_t	ft_strlenchr(const char *str, const char c);

char	*get_next_line(int fd);

#endif
