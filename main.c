/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:12:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/05 15:24:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
/*
	char	*str;
	char	*buffer = "";

	(void)ac;
	(void)av;
	str = ft_strjoin("lol", dup_until(buffer, 'a'));
	printf("%s", str);
*/
	int		fd;
	char	*line;

	if (ac == 1 || (fd = open(av[1], O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("[%s]\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
