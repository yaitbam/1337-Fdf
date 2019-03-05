/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:56 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/03 14:13:04 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			event_key_next(int keycode, t_env *env)
{
	if (keycode == 78)
	{
		env->scale.x -= 1;
		env->scale.y += 1;
	}
	if (keycode == 121)
	{
		env->alt -= 1;
		apply_height(env, -1);
	}
	if (keycode == 6)
		env->color = CZ;
	if (keycode == 7)
		env->color = CX;
	if (keycode == 8)
		env->color = CC;
	if (keycode == 9)
		env->color = CV;
	if (keycode == 11)
		env->color = CB;
	if (keycode == 45)
		env->color = CN;
	draw_again(env);
	str_menu_key(env);
	return (1);
}

void		str_menu_key(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 0, 10, 0x6752d9,
			"=========[    Touches   ]=========");
	mlx_string_put(env->mlx, env->win, 0, 40, 0xFFFFFF, "Quitter       :");
	mlx_string_put(env->mlx, env->win, 160, 40, 0x8f8f8f, "Echap");
	mlx_string_put(env->mlx, env->win, 0, 60, 0xFFFFFF, "Deplacement   :");
	mlx_string_put(env->mlx, env->win, 160, 60, 0x8f8f8f, "Fleches");
	mlx_string_put(env->mlx, env->win, 0, 80, 0xFFFFFF, "Couleurs      :");
	mlx_string_put(env->mlx, env->win, 160, 80, 0x8f8f8f, "x,c,v,b,n");
	mlx_string_put(env->mlx, env->win, 0, 100, 0xFFFFFF, "Zoom          :");
	mlx_string_put(env->mlx, env->win, 160, 100, 0x8f8f8f, "+ | -");
	mlx_string_put(env->mlx, env->win, 0, 120, 0xFFFFFF, "Hauteur       :");
	mlx_string_put(env->mlx, env->win, 160, 120, 0x8f8f8f,
			"page up | page down");
	mlx_string_put(env->mlx, env->win, 0, 140, 0xFFFFFF, "Color		   :");
	mlx_string_put(env->mlx, env->win, 180, 140, 0x8f8f8f, "mouse");
}

int			event_key(int keycode, t_env *env)
{
	if (keycode == 35)
		env->proj = 'P';
	else if (keycode == 34)
		env->proj = 'I';
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		env->pos.x += 30;
	if (keycode == 125)
		env->pos.y += 30;
	if (keycode == 123)
		env->pos.x -= 30;
	if (keycode == 126)
		env->pos.y -= 30;
	if (keycode == 116)
	{
		env->alt += 1;
		apply_height(env, 1);
	}
	if (keycode == 69)
	{
		env->scale.x += 1;
		env->scale.y -= 1;
	}
	return (event_key_next(keycode, env));
}

int			event_mouse(int button, int x, int y, t_env *env)
{
	if (button == 1 && x && y)
	{
		if (env->color == CZ)
			env->color = CX;
		else if (env->color == CX)
			env->color = CC;
		else if (env->color == CC)
			env->color = CV;
		else if (env->color == CV)
			env->color = CB;
		else if (env->color == CB)
			env->color = CN;
		else
			env->color = CZ;
		draw_again(env);
		str_menu_key(env);
	}
	return (1);
}
