/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:00:16 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/21 23:30:35 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test_stdin(void)
{
	int		ret;
	char	buffer[101];

	printf("\n\e[4m  STANDART INPUT  \e[0m\n\n");
	ret = read(0, buffer, 100);
	buffer[ret] = '\0';
	printf("read buffer    = \"%s\"\n", buffer);
	printf("read return    = %d\n", ret);
	printf("read errno     = %d\n\n", errno);
	ret = ft_read(0, buffer, 100);
	buffer[ret] = '\0';
	printf("ft_read buffer = \"%s\"\n", buffer);
	printf("ft_read return = %d\n", ret);
	printf("ft_read erno   = %d\n", errno);
	bzero(buffer, 100);
	printf("----------------------------\n");
}

static void	test_fd(char *file)
{
	int		fd;
	int		ret;
	char	buffer[101];

	printf("\n\e[4m  FILE DESCRIPTOR  \e[0m\n\n");
	fd = open(file, O_RDWR);
	ret = read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("read buffer    = \"%s\"\n", buffer);
	printf("read return    = %d\n", ret);
	printf("read errno     = %d\n\n", errno);
	close(fd);
	bzero(buffer, 100);
	errno = 0;
	fd = open(file, O_RDWR);
	ret = ft_read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("ft_read buffer = \"%s\"\n", buffer);
	printf("ft_read return = %d\n", ret);
	printf("ft_read erno   = %d\n", errno);
	close(fd);
	bzero(buffer, 100);
	printf("----------------------------\n");
}

void		test_ft_read(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_READ  ~~~~~~\e[0m\n");
	test_stdin();
	test_fd("main_read.txt");
	test_fd("dont_exist.txt");
}
