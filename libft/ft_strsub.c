/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:10:15 by yait-bam          #+#    #+#             */
/*   Updated: 2019/01/23 13:14:58 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	ret = ft_strnew(len);
	if (ret)
	{
		ft_strncat(ret, (s + start), len);
		ft_strcat((ret + ft_strlen(ret)), "\0");
	}
	return (ret);
}
