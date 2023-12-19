/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:33:34 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/19 10:00:14 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS.H
# define GET_NEXT_LINE_BONUS.H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char	*buffer;
	int		fd;
	s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif