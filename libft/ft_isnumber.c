/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:50:40 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/12 09:51:07 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isnumber(int c)
{
	return (c >= '0' && c <= '9');
}