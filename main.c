/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:44:04 by caalbert          #+#    #+#             */
/*   Updated: 2022/07/22 02:54:34 by caalbert         ###   ########.fr       */
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
	int		fd;
	// int		fd2;
	int		i;
	// int		show_lines;

	(void) i;
	// (void) show_lines = 10;
	pathname = "./utils/file.txt";
	// (void) pathname2 = "./utils/file.txt";
	fd = open(pathname, 256);
	// (void) fd2 = open(pathname2, 256);
	/* Loop to returns first 10 lines read */
	// i = 0;
	// while (i <= show_lines)
	// {
	// 	gnl = get_next_line(fd);
	// 	printf("Line %d: %s", ++i, gnl);
	// 	gnl2 = get_next_line(fd2);
	// 	printf("Line %d: %s", ++i, gnl2);
	// 	free(gnl);
	// 	free(gnl2);
	// }

	/* Returns line to input on terminal */
	gnl = get_next_line(fd);
	printf("Return: %s", gnl);
	free(gnl);

	/* Returns all lines read */
	// gnl = get_next_line(0);
	// printf("Return: %s", gnl);
	// free(gnl);

}
