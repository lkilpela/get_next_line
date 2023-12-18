/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:23:55 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/18 15:18:44 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char	*buffer;
	size_t	used;
	size_t	size;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*merge_string(char *s1, char *s2);

#endif
