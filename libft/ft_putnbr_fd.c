/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:16:52 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/11 18:43:32 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put(int n, int fd)
{
	if (n / 10)
	{
		put(n / 10, fd);
		put(n % 10, fd);
	}
	else if (n > 0)
		ft_putchar_fd('0' + n, fd);
	else
		ft_putchar_fd('0' + -n, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	put(n, fd);
}
