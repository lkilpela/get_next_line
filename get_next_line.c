/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:32 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/18 13:21:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_newline(int fd, char *buffer);
static char	*extract_first_line(char *buffer);
static void adjust_buffer(char *buffer, char *line);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_until_newline(fd, buffer);
	if (!buffer || !*buffer)
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
	adjust_buffer(buffer, line);
	return (line);
}

//reads from a file descriptor fd into a buffer until it encounters 
//a newline character or reaches the end of the file
static char	*read_until_newline(int fd, char *buffer)
{
	char	*line;
	int		read_bytes;
	char	*temp;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	read_bytes = 1;
	while ((read_bytes = read(fd, line, BUFFER_SIZE)) > 0)
	{
		line[read_bytes] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		if (!buffer)
			return (NULL);
		temp = buffer;
		buffer = ft_strjoin(temp, line);
		free(temp);
		if (!buffer)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	if (read_bytes == -1)
	{
		free(line);
		free(buffer);
		return (0);
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

static void adjust_buffer(char *buffer, char *line)
{
	size_t	line_len;
	size_t	newbuffer_len;
	size_t	i;

	line_len = ft_strlen(line);
	newbuffer_len = ft_strlen(buffer) - line_len;
	i = 0;
	while (i < newbuffer_len)
	{
		buffer[i] = buffer[i + line_len];
		i++;
	}
	buffer[newbuffer_len] = '\0';
}
