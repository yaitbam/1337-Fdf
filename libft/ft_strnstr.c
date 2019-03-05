/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:12:01 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/10 16:47:00 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*s2 || !s2)
		return ((char *)s1);
	j = 0;
	while (s1[j] && j < n)
	{
		i = 0;
		while (s1[j + i] == s2[i] && (i + j) < n)
		{
			i++;
			if (!s2[i])
				return ((char *)&s1[j]);
		}
		j++;
	}
	return (NULL);
}
