/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:14:28 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/20 14:45:19 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *c;

	c = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (c)
	{
		ft_strcpy(c, s1);
		ft_strcat((c + ft_strlen(s1)), s2);
	}
	return (c);
}
