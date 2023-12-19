/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:51:51 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/19 10:48:39 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *read_until_newline(int fd, char *buffer);
static char *extract_line(char *buffer);
static char *merge_string(char **bufer);

char	*get_next_line_bonus(int fd)
{
	static t_list	*fd_list;
	t_list			*current_fd;
	char			*line;
	
	if (fd < 0)
		return (NULL);
	

}

static char *read_until_newline(int fd, char *buffer)
{
    char	*read_buff[BUFFER_SIZE + 1];
    int		read_count;

	read_count = read(fd, read_buff, BUFFER_SIZE);
	while (read_count > 0)
	{
		read_buff[read_count] = '\0';
		buffer = merge_string(buffer, read_buff);
		if (!buffer || ft_strchr(read_buff, '\n'))
			break ;
		read_count = read(fd, read_buff, BUFFER_SIZE);		
	}
	if (read_count < 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
static char *extract_line(char **buffer);
static char *merge_string(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result)
	{
		ft_memcpy(result, s1, len1);
		ft_memcpy(result + len1, s2, len2);
		result[len1 + len2] = '\0';
	}
	free (s1);
	return (result);
}

