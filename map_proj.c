/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:34 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/03 14:13:18 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static	int		proj_x(int x, int y, t_env *env)
{
	float	ret;

	ret = (sqrt(2) / 2) * (x - y);
	ret *= env->scale.x;
	return ((int)ret);
}

static	int		proj_y(int x, int y, t_env *env)
{
	float	ret;

	ret = (sqrt(3) / 4) * env->map[y][x].z;
	ret -= (1 / sqrt(6) * (x + y));
	ret *= env->scale.y;
	return ((int)ret);
}

void			apply_height(t_env *env, int c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			if (env->map[y][x].z0 != 0)
			{
				if (c == 1)
					env->map[y][x].z = (env->map[y][x].z0 * env->alt);
				else
					env->map[y][x].z = (env->map[y][x].z0 * env->alt);
				env->map[y][x].xp = proj_x(x, y, env);
				env->map[y][x].yp = proj_y(x, y, env);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void			apply_proj(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			env->map[y][x].xp = proj_x(x, y, env);
			env->map[y][x].yp = proj_y(x, y, env);
			x++;
		}
		x = 0;
		y++;
	}
}
