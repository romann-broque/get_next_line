/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:34:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/07 22:20:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		ret_val;
	int		fd;
	char	*line;

	ret_val = EXIT_SUCCESS;
	for (int i = 1; i < ac; ++i)
	{
		if (ac == 1 || (fd = open(av[i], O_RDONLY)) == -1)
		{
			ret_val = EXIT_FAILURE;
			break ;
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
	}
	return (ret_val);
}
