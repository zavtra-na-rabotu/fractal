/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:25 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:28 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_correct_file_data(t_list **file, int fd)
{
	t_list *temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

static size_t	cpy_to_char(char **dst, char *src, char c)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			break ;
		i++;
	}
	*dst = ft_strnew(i);
	if (!(*dst))
		return (0);
	ft_strncpy(*dst, src, i);
	return (i);
}

static size_t	reading_loop(int fd, t_list *cur)
{
	char			*buffer;
	size_t			red;
	char			*temp;

	buffer = (char *)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (-1);
	while ((red = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[red] = '\0';
		if (!(temp = (char *)ft_strjoin(cur->content, buffer)))
		{
			free(buffer);
			return (-1);
		}
		free(cur->content);
		cur->content = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (red);
}

int				delete_node(t_list **head, size_t fd)
{
	t_list *temp;
	t_list *prev;

	temp = *head;
	if (temp != NULL && temp->content_size == fd)
	{
		*head = temp->next;
		free(temp);
		return (0);
	}
	while (temp != NULL && temp->content_size != fd)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	prev->next = temp->next;
	free(temp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	size_t			red;
	static t_list	*file;
	t_list			*cur;
	char			*temp;

	if ((fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0))
		return (-1);
	cur = get_correct_file_data(&file, fd);
	red = reading_loop(fd, cur);
	if (-red == 1)
		return (-1);
	if (!cur->content || (red < BUFF_SIZE && !ft_strlen(cur->content)))
	{
		ft_strdel((char **)&cur->content);
		return (delete_node(&file, cur->content_size));
	}
	if ((red = cpy_to_char(line, cur->content, '\n')) < ft_strlen(cur->content))
	{
		temp = cur->content;
		cur->content = ft_strdup(&(((char *)cur->content)[red + 1]));
		free(temp);
	}
	else
		ft_strclr(cur->content);
	return (1);
}
