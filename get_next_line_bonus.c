/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:16:27 by caalbert          #+#    #+#             */
/*   Updated: 2022/07/20 20:54:25 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_mem(void **ptr);
char	*read_line(t_list **buffer_lists, t_list *last, int len, int fd);
char	*join_lines(size_t end, int len, t_list **buffer_lists);
void	convert_lts_to_str(t_list **buffer_lists, int strlen, char *str);

char	*get_next_line(int fd)
{
	static t_list	*buffer_list[MAX_FD + 1];
	char			*text;

	if (BUFFER_SIZE <= 0 || fd > MAX_FD || fd < 0)
		return (NULL);
	if (buffer_list[fd] == NULL)
		buffer_list[fd] = ft_lstnew(ft_strdup(""));
	text = read_line(&buffer_list[fd], buffer_list[fd],
			ft_strlen(buffer_list[fd]->line), fd);
	return (text);
}

void	free_mem(void **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*read_line(t_list **buffer_lists, t_list *last, int len, int fd)
{
	char		*text;
	t_list		*final;
	ssize_t		bytes_read_on_file;

	text = ft_strchr(last->line, '\n');
	if (text != NULL)
	{
		bytes_read_on_file = ft_strlen(text + 1);
		return (join_lines(bytes_read_on_file, len, &buffer_lists[0]));
	}
	text = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (text == NULL)
		return (NULL);
	bytes_read_on_file = read(fd, text, BUFFER_SIZE);
	if (bytes_read_on_file <= 0)
	{
		free_mem((void **)&text);
		return (join_lines(bytes_read_on_file, len, &buffer_lists[0]));
	}
	else
		len += bytes_read_on_file;
	text[bytes_read_on_file] = 0;
	final = ft_lstnew(text);
	last->next = final;
	return (read_line(&buffer_lists[0], final, len, fd));
}

char	*join_lines(size_t end, int len, t_list **buffer_lists)
{
	int		str_len;
	char	*res;

	res = NULL;
	if (len <= 0)
	{
		free_mem((void **)&buffer_lists[0]->line);
		free_mem((void **)buffer_lists);
		return (NULL);
	}
	str_len = len - end;
	res = (char *)malloc(str_len + 1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[str_len] = 0;
	convert_lts_to_str(buffer_lists, str_len, res);
	return (res);
}

void	convert_lts_to_str(t_list **buffer_lists, int strlen, char *str)
{
	t_list	*tmp;
	char	*content;
	int		i;

	i = 0;
	while (i < strlen)
	{
		tmp = buffer_lists[0];
		content = (char *)tmp->line;
		while (*content != 0 && i < strlen)
		{
			str[i] = *content;
			content++;
			i++;
		}
		if (*content != 0)
			buffer_lists[0]->next = ft_lstnew(ft_strdup(content));
		buffer_lists[0] = buffer_lists[0]->next;
		free_mem((void **)&tmp->line);
		free_mem((void **)&tmp);
	}
}
