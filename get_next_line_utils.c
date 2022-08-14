/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:16:16 by caalbert          #+#    #+#             */
/*   Updated: 2022/07/12 22:44:53 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s && c != *s)
		s++;
	if (*s == '\0' && c != '\0')
		return (NULL);
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	dst = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s)
		dst[i++] = *s++;
	dst[i] = '\0';
	return (dst);
}

t_list	*ft_lstnew(void *line)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}
