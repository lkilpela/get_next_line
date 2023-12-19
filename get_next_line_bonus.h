/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:33:34 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/19 09:37:57 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS.H
# define GET_NEXT_LINE_BONUS.H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char	*buffer;
	size_t	used;
	size_t	size;
}				t_list;

#endif