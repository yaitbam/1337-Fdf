/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:57:18 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/14 14:21:52 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_src;
	unsigned char	*t_dst;
	size_t			i;

	i = 0;
	t_src = (unsigned char *)src;
	t_dst = (unsigned char *)dst;
	if (t_src < t_dst)
		while (len--)
			t_dst[len] = t_src[len];
	else
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	return (dst);
}
