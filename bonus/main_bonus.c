/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:34:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/09 15:46:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FINISHED true
#define NOT_FINISHED false

typedef struct s_file_stat
{
	int		fd;
	bool	status;
}				t_file_stat;

bool	display_lines(int fd, size_t n)
{
	size_t		i;
	static char	*line = NULL;

	if (line == NULL && n > 0)
	{
		line = get_next_line(fd);
		--n;
	}
	i = 0;
	while (line != NULL && i < n)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	return (line == NULL);
}

t_file_stat	*init_f_stat(int nb_files, char **file_paths)
{
	t_file_stat	*f_stat;

	f_stat = (t_file_stat *)malloc(nb_files * sizeof(t_file_stat));
	if (f_stat != NULL)
	{
		for (int i = 0; i < nb_files; ++i)
		{
			f_stat[i].fd = open(file_paths[i], O_RDONLY);
			f_stat[i].status = NOT_FINISHED;
		}
	}
	return (f_stat);
}

bool	are_finished(t_file_stat *f_stat, size_t size)
{
	bool	are_finished;
	size_t	i;

	are_finished = FINISHED;
	i = 0;
	while (i < size)
	{
		if (f_stat[i].status == NOT_FINISHED)
		{
			are_finished = NOT_FINISHED;
			break ;
		}
		++i;
	}
	return (are_finished);
}

void	close_fds(t_file_stat *f_stat, size_t nb_files)
{
	size_t	i;

	i = 0;
	while (i < nb_files)
	{
		if (f_stat->fd > -1 && f_stat->fd < OPEN_MAX)
			close(f_stat->fd);
		++i;
	}
}

int	main(int ac, char **av)
{
	int			ret_val;
	t_file_stat	*f_stat;

	--ac;
	++av;
	ret_val = EXIT_SUCCESS;
	f_stat = init_f_stat(ac, av);
	while (are_finished(f_stat, ac) == NOT_FINISHED)
	{
		for (int i = 0; i < ac; ++i)
			f_stat[i].status = display_lines(f_stat[i].fd, INTER_LINE);
	}
	close_fds(f_stat, ac);
	free(f_stat);
	return (ret_val);
}
