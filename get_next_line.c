/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:32 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/18 15:43:02 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_newline(int fd, char *buffer);
static char	*extract_line(char **buffer);
static char	*merge_string(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = read_until_newline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line && buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

static char	*read_until_newline(int fd, char *buffer)
{
	int		read_count;
	char	read_buf[BUFFER_SIZE + 1];

	read_count = read(fd, read_buf, BUFFER_SIZE);
	while (i > 0)
	{
		read_buf[read_count] = '\0';
		buffer = merge_string(buffer, read_buf);
		if (!buffer || ft_strchr(read_buf, '\n'))
			break ;
		read_count = read(fd, read_buf, BUFFER_SIZE);
	}
	if (read_count < 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*copy;
	char	*pos;

	line = *buffer;
	pos = ft_strchr(line, '\n');
	if (pos)
	{
		*buffer = ft_strdup(pos + 1);
		pos[1] = '\0';
	}
	else
	{
		line = *buffer;
		*buffer = NULL;
	}
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	copy = ft_strdup(line);
	free(line);
	return (copy);
}
static char	*merge_string(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *) malloc(s1_len + s2_len) + 1);
	if (result)
	{
		ft_memcpy(result, s1, s1_len);
		ft_memcpy(result + s1_len, s2, s2_len);
		result[s1_len + s2_len] = '\0';
	}
	free(s1);
	return (result);
}
