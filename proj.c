/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:45:49 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/02 12:55:55 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		proj2_x(int x, int y, t_env *env)
{
	int	ret;

	ret = env->map[y][x].z;
	ret = x;
	ret *= env->scale.x;
	return (ret);
}

static	int		proj2_y(int x, int y, t_env *env)
{
	int	ret;

	ret = env->map[y][x].z;
	ret -= y;
	ret *= env->scale.y;
	return (ret);
}

void			apply_proj2(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			env->map[y][x].xp = proj2_x(x, y, env);
			env->map[y][x].yp = proj2_y(x, y, env);
			x++;
		}
		x = 0;
		y++;
	}
}
