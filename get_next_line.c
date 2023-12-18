/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:32 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/18 15:34:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_newline(int fd, char *buffer);
static char	*extract_line(char **buffer);

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
	int		i;
	char	array[BUFFER_SIZE + 1];

	i = read(fd, array, BUFFER_SIZE);
	while (i > 0)
	{
		array[i] = '\0';
		buffer = merge_string(buffer, array);
		if (!buffer || ft_strchr(array, '\n'))
			break ;
		i = read(fd, array, BUFFER_SIZE);
	}
	if (i < 0 || !buffer)
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
