/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:34:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/07 18:34:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(const char *s, const size_t size)
{
	char	*dup;

	dup = (char *)malloc((size + 1) * sizeof(char));
	if (dup != NULL)
		ft_strncpy(dup, (char *)s, size);
	return (dup);
}

size_t	ft_strlenchr(const char *str, const char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		++len;
	return (len);
}

void	ft_bzero(void *ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((uint8_t *)ptr)[i] = 0;
		++i;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != '\0')
		++s;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
