/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-bam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:18:25 by yait-bam          #+#    #+#             */
/*   Updated: 2019/01/23 13:18:28 by yait-bam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct				s_fbuffer
{
	int						fd;
	char					*data;
}							t_fbuffer;

int							get_next_line(const int fd, char **line);

#endif
