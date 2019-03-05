/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:04:37 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/10 16:30:40 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	see;
	int		len;

	str = (char *)s;
	see = (char)c;
	len = ft_strlen(str);
	while ((len != 0) && str[len] != see)
		len--;
	if (str[len] == see)
		return (&str[len]);
	return (NULL);
}
