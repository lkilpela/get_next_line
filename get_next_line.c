/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:32 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/12 15:54:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = read_until_newline(fd, buffer);
	if (!buffer)
		return (NULL);	
}

/*reads from a file descriptor fd into a buffer until it encounters 
a newline character or reaches the end of the file*/
static char	*read_until_newline(int fd, char *buffer)
{
	char	*line;
	int		read_bytes;
	char	*temp;

	line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!line)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, line, BUFF_SIZE);
		if (read_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		line[read_bytes] = '\0';
		temp = ft_strjoin(buffer, line);
		free(buffer);
		buffer = temp;
		if (ft_strchr(line, '\n'))
			break ;
	}
	free (line);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*newline_pos;
	char	*line;
	size_t	line_len;

	if (!buffer)
		return (NULL);
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos != NULL)
		line_len = newline_pos - buffer + 1;
	else
		line_len = ft_strlen(buffer);
	line = (char *)malloc(sizeof(char) * line_len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, line_len);
	line[line_len] = '\0';
	return (line);
}
