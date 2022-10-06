/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:09:26 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/06 17:00:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define EMPTY_STRING ""

char	*ft_strncpy(char *dest, char *src, size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *ptr, size_t size);
char	*ft_strndup(const char *str, const size_t size);
size_t	ft_strlenchr(const char *str, const char c);

char	*get_next_line(int fd);

#endif
