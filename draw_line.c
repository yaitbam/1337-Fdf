/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:48:57 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/03 14:12:56 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		draw_line(t_env *env, t_coord p1, t_coord p2)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = ft_abs(p2.x - p1.x);
	dy = ft_abs(p2.y - p1.y);
	s[0] = (p1.x < p2.x ? 1 : -1);
	s[1] = (p1.y < p2.y ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		pixel_put(env, p1.x, p1.y, env->color);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			p1.x += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			p1.y += s[1];
		}
	}
}

void			draw_again(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	apply_proj(env);
	if (env->proj == 'P')
		apply_proj2(env);
	mlx_clear_window(env->mlx, env->win);
	while (y < env->height)
	{
		while (x < env->width)
		{
			draw_lines(env, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void			draw_again2(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	apply_proj2(env);
	mlx_clear_window(env->mlx, env->win);
	while (y < env->height)
	{
		while (x < env->width)
		{
			draw_lines(env, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void			draw_lines(t_env *env, int x, int y)
{
	t_coord p[2];

	p[0].x = env->map[y][x].xp;
	p[0].y = env->map[y][x].yp;
	if (x < env->width - 1)
	{
		p[1].x = env->map[y][x + 1].xp;
		p[1].y = env->map[y][x + 1].yp;
		draw_line(env, p[0], p[1]);
	}
	if (y < env->height - 1)
	{
		p[1].x = env->map[y + 1][x].xp;
		p[1].y = env->map[y + 1][x].yp;
		draw_line(env, p[0], p[1]);
	}
}
