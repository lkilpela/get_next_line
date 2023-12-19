/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:51:51 by lkilpela          #+#    #+#             */
/*   Updated: 2023/12/19 11:58:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*find_or_create_fd_node(t_list **head, int fd);
static char		*read_until_newline(int fd, char *buffer);
static char		*extract_line(char **buffer);
static char		*merge_string(char *s1, char *s2);

char	*get_next_line_bonus(int fd)
{
	static t_list	*head;
	t_list			*current_fd;
	char			*line;

	if (fd < 0)
		return (NULL);
	current_fd = find_or_create_fd_node(&head, fd);
	if (!current_fd)
		return (NULL);
	current_fd->buffer = read_until_newline(fd, current_fd->buffer);
	if (!current_fd->buffer)
		return (NULL);
	line = extract_line(&current_fd->buffer);
	if (!line && current_fd->buffer)
	{
		remove_fd_node(&head, fd);
		current_fd->buffer = NULL;
	}
	return (line);
}

static t_list	*find_or_create_fd_node(t_list **head, int fd)
{
	t_list	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->fd = fd;
	temp->buffer = NULL;
	temp->next = *head;
	*head = temp;
	return (temp);
}

static char	*read_until_newline(int fd, char *buffer)
{
	char	read_buff[BUFFER_SIZE + 1];
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

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*pos;
	char	*copy;

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
		buffer = NULL;
	}
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	copy = ft_strdup(line);
	free (line);
	return (copy);
}

static char	*merge_string(char *s1, char *s2)
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
