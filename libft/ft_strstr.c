/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:04:40 by yait-bam          #+#    #+#             */
/*   Updated: 2018/11/07 15:06:27 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		i = 0;
		while (s2[j] != '\0' && s2[j] == s1[i])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(s1));
		s1++;
	}
	return (NULL);
}
