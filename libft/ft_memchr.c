/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:07:37 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/16 11:30:10 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *p;

	p = (char*)s;
	while (n--)
	{
		if (*p != (char)c)
			p++;
		else
			return (p);
	}
	return (0);
}