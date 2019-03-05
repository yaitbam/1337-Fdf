/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:15:20 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/12 14:31:48 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if (ft_strlen(s1) >= n && ft_strlen(s2) >= n)
		return (ft_memcmp(s1, s2, n));
	else
	{
		if (ft_strlen(s1) > ft_strlen(s2))
			return (ft_memcmp(s1, s2, ft_strlen(s2) + 1));
		else
			return (ft_memcmp(s1, s2, ft_strlen(s1) + 1));
	}
}
