/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:07:57 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/14 14:24:45 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (*p1 == *p2)
	{
		n--;
		if (!n)
			return (0);
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
