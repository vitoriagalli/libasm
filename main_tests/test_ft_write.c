/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 00:59:59 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/20 04:37:26 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test_stdout(char *str)
{
	int		ret;

	printf("\n\e[4m  STANDART OUTPUT  \e[0m\n\n");
	printf("string    = \"%s\"\n\n", str);
	ret = write(1, "write           = \"", 19);
	ret += write(1, str, ft_strlen(str));
	ret += write(1, "\"\n", 2);
	printf("write return    = %d\n", ret);
	printf("write errno     = %d\n", errno);
	ret = ft_write(1, "ft_write        = \"", 19);
	ret += ft_write(1, str, ft_strlen(str));
	ret += ft_write(1, "\"\n", 2);
	printf("ft_write return = %d\n", ret);
	printf("ft_write errno  = %d\n", errno);
	printf("----------------------------\n");
}

static void	test_fd(char *file, char *str)
{
	int		fd;
	int		ret;

	printf("\n\e[4m  FILE DESCRIPTOR  \e[0m\n\n");
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	printf("string to write    = \"%s\"\n\n", str);
	ret = write(fd, "write      = \"", 14);
	ret += write(fd, str, ft_strlen(str));
	ret += write(fd, "\"\n", 2);
	printf("write errno     = %d\n", errno);
	printf("write return    = %d\n", ret);
	errno = 0;
	ret = ft_write(fd, "ft_write   = \"", 14);
	ret += ft_write(fd, str, ft_strlen(str));
	ret += ft_write(fd, "\"\n", 2);
	printf("ft_write errno  = %d\n", errno);
	printf("ft_write return = %d\n", ret);
	printf("\e[3m(check \"%s\" file)\e[0m\n", file);
	close(fd);
	printf("----------------------------\n");
}

void		test_ft_write(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_WRITE  ~~~~~~\e[0m\n");
	test_stdout("Hello World");
	test_fd("write_file.txt", "this is string must be into the file");
	test_fd("another.txt", "another test");
}
