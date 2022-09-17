/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:44:04 by caalbert          #+#    #+#             */
/*   Updated: 2022/09/17 11:38:57 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


char	*get_next_line(int fd);

int	main(void)
{
	char	*pathname;
	// char	*pathname2;
	char	*gnl;
	// char	*gnl2;
	// int		fd;
	int		fd2;
	int		i;
	int		show_lines;

	show_lines = 10;
	pathname = "./utils/42.fdf";
	fd2 = open(pathname, 256);
	/* Loop to returns first 10 lines read */
	i = 0;
	while (i <= show_lines)
	{
		gnl = get_next_line(fd2);
		printf("Line %d: %s", ++i, gnl);
		free(gnl);
	}

	/* Returns line to input on terminal */
	// gnl = get_next_line(fd);
	// printf("Return: %s", gnl);
	// free(gnl);

	/* Returns all lines read */
	// gnl = get_next_line(0);
	// printf("Return: %s", gnl);
	// free(gnl);

}
