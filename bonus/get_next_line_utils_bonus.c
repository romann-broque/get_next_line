/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:34:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/10 14:57:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

size_t	index_of(const char *str, const char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		++len;
	return (len);
}

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

char	*strnjoin(char *s1, const char *s2, const size_t n)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	len1 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > n)
		len2 = n;
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		if (s1 != NULL)
			ft_strncpy(new, (char *)s1, len1);
		ft_strncpy(new + len1, (char *)s2, len2);
	}
	free(s1);
	return (new);
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
