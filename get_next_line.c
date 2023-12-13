/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:32 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/13 14:25:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(int fd, char *buffer);
static char	*extract_first_line(char *buffer);
static char	*adjust_buffer(char *buffer, char *line);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = read_until_newline(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_first_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = adjust_buffer(buffer, line);
	return (line);
}

//reads from a file descriptor fd into a buffer until it encounters 
//a newline character or reaches the end of the file
static char	*read_until_newline(int fd, char *buffer)
{
	int		read_bytes;
	char	*line;
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

// extract the first line of text from the buffer
static char	*extract_first_line(char *buffer)
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

static char	*adjust_buffer(char *buffer, char *line)
{
	size_t	line_len;
	size_t	newbuffer_len;

	line_len = ft_strlen(line);
	newbuffer_len = ft_strlen(buffer) - line_len;
	ft_memmove(buffer, buffer + line_len, newbuffer_len);
	buffer[newbuffer_len] = '\0';
	return (buffer);
}
