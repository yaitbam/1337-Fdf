/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:53:07 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/13 14:26:00 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*c;

	if (!(c = ft_strnew(ft_strlen(s))))
		return (c);
	i = 0;
	while (s[i])
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
