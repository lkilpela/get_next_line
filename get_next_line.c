/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:32 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/12 15:08:09 by lkilpela         ###   ########.fr       */
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
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
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
	}
	free (line);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	
}