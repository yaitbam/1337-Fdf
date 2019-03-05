/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:24:27 by yait-bam          #+#    #+#             */
/*   Updated: 2018/10/25 20:43:53 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*sc;

	if (!s)
		return (NULL);
	if (!(sc = ft_strdup(s)))
		return (NULL);
	while (*sc == ' ' || *sc == '\n' || *sc == '\t')
		sc++;
	i = ft_strlen(sc) - 1;
	while (sc[i] == ' ' || sc[i] == '\n' || sc[i] == '\t')
		i--;
	sc[++i] = '\0';
	if (!(sc = ft_strdup(sc)))
		return (NULL);
	if (sc)
		return (sc);
	return (NULL);
}
