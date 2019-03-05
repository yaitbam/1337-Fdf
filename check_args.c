/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:48:39 by yait-bam          #+#    #+#             */
/*   Updated: 2019/02/02 21:35:29 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_args(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("You did not pass the right number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		exit(0);
	}
}

void		exit_error(int c)
{
	if (c == 1)
		ft_putstr_fd("Error: Map is invalid\n", 2);
	if (c == 2)
		ft_putstr_fd("Error: mlx failed\n", 2);
	exit(0);
}
