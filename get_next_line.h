/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:16:07 by caalbert          #+#    #+#             */
/*   Updated: 2022/07/14 01:32:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

typedef struct s_list
{
	void			*line;
	struct s_list	*next;
}	t_list;

/**
 * @brief Get the next line object
 *
 * @param fd
 * @return char* Returns and chain of chars 
 */
char	*get_next_line(int fd);
/**
 * @brief
 *
 * @param s
 * @param c
 * @return char*
 */
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
t_list	*ft_lstnew(void *line);

#endif
