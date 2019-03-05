/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:48:13 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/03 13:50:53 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static	int		count_words(const char *line)
{
	int		count;
	int		i;
	int		len;
	char	lastchar;

	i = 0;
	count = 0;
	len = ft_strlen(line);
	if (len > 0)
		lastchar = line[0];
	while (i <= len)
	{
		if ((line[i] == ' ' || line[i] == '\0') && lastchar != ' ')
			count++;
		lastchar = line[i];
		i++;
	}
	return (count);
}

static int		get_info(char *file, int c)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = open(file, O_RDONLY);
	if (c == 1)
	{
		while (get_next_line(fd, &line) > 0)
			ret++;
		close(fd);
	}
	else
	{
		get_next_line(fd, &line);
		ret = count_words(line);
		while (get_next_line(fd, &line) > 0)
		{
			if (count_words(line) != ret)
				exit_error(1);
		}
		close(fd);
	}
	return (ret);
}

void			parse_args(char *file, t_env *env)
{
	int i;

	i = 0;
	env->height = get_info(file, 1);
	env->width = get_info(file, 2);
	env->map = (t_point **)malloc(sizeof(t_point *) * env->height);
	while (i < env->height)
	{
		env->map[i] = (t_point *)malloc(sizeof(t_point) * env->width);
		i++;
	}
}

void			smallest(t_env *env, int x, int y, int c)
{
	int	tmp;

	if (c == 0)
	{
		tmp = ft_abs(env->map[y][x].z);
		if ((!env->smallest && tmp != 0) || (env->smallest > tmp && tmp != 0))
			env->smallest = tmp;
	}
	else
	{
		if (!env->smallest)
			env->smallest = 1;
		while (y < env->height)
		{
			while (x < env->width)
			{
				env->map[y][x].z /= env->smallest;
				env->map[y][x].z0 /= env->smallest;
				x++;
			}
			x = 0;
			y++;
		}
	}
}
