/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:00:16 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/25 04:35:24 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test_orig(int fd, char *buffer)
{
	int ret;

	bzero(buffer, 101);
	ret = read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("read buffer    = \"%s\"\n", buffer);
	printf("read return    = %d\n", ret);
	printf("read errno     = %d\n\n", errno);
	errno = 0;
}

static void	test_implem(int fd, char *buffer)
{
	int ret;

	bzero(buffer, 101);
	ret = ft_read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("ft_read buffer = \"%s\"\n", buffer);
	printf("ft_read return = %d\n", ret);
	printf("ft_read erno   = %d\n", errno);
	errno = 0;
}

void		test_ft_read(void)
{
	char	buffer[101];
	int		fd;

	printf("\n\n\e[1;1m~~~~~~  FT_READ  ~~~~~~\e[0m\n");
	printf("\n\e[4m  STANDART INPUT  \e[0m\n\n");
	test_orig(STDIN_FILENO, buffer);
	test_implem(STDIN_FILENO, buffer);
	printf("----------------------------\n");
	printf("\n\e[4m  OPEN FILE DESCRIPTOR  \e[0m\n\n");
	fd = open("main_read.txt", O_RDWR);
	test_orig(fd, buffer);
	close(fd);
	fd = open("main_read.txt", O_RDWR);
	test_implem(fd, buffer);
	close(fd);
	printf("----------------------------\n");
	printf("\n\e[4m  WRONG FILE DESCRIPTOR  \e[0m\n\n");
	fd = open("main_read.txt", O_RDWR);
	test_orig(fd + 5, buffer);
	close(fd);
	fd = open("main_read.txt", O_RDWR);
	test_implem(fd + 5, buffer);
	close(fd);
}
