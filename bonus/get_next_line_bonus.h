/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:33:46 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/08 10:14:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

size_t	ft_strlen(const char *str);
size_t	index_of(const char *str, const char c);
char	*ft_strncpy(char *dest, char *src, size_t size);
char	*strnjoin(char *s1, const char *s2, const size_t n);
void	ft_bzero(void *ptr, size_t size);

char	*get_next_line(int fd);

#endif
