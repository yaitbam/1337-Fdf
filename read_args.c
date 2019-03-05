/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:43:00 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/03 14:12:18 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		split(char *line, int fd, t_env *env)
{
	char	**line_split;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_split = ft_strsplit(line, ' ');
		while (*line_split != NULL)
		{
			env->map[y][x].z = ft_atoi(*line_split);
			smallest(env, x, y, 0);
			env->map[y][x].z0 = env->map[y][x].z;
			x++;
			line_split++;
		}
		x = 0;
		y++;
	}
}

void			read_args(char *file, t_env *env)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(1);
	split(file, fd, env);
	close(fd);
	smallest(env, 0, 0, 1);
}
