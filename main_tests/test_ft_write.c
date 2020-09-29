/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 00:59:59 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/25 04:50:39 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test(int fd, char *str)
{
	int		ret;

	printf("string    = \"%s\"\n\n", str);
	ret = write(fd, "write           = \"", 19);
	ret += write(fd, str, ft_strlen(str));
	ret += write(fd, "\"\n", 2);
	printf("write errno     = %d\n", errno);
	printf("write return    = %d\n", ret);
	errno = 0;
	ret = ft_write(fd, "ft_write        = \"", 19);
	ret += ft_write(fd, str, ft_strlen(str));
	ret += ft_write(fd, "\"\n", 2);
	printf("ft_write errno  = %d\n", errno);
	printf("ft_write return = %d\n", ret);
	errno = 0;
}

void		test_ft_write(void)
{
	int		fd;
	char	*file;

	printf("\n\n\e[1;1m~~~~~~  FT_WRITE  ~~~~~~\e[0m\n");
	printf("\n\e[4m  STANDART OUTPUT  \e[0m\n\n");
	test(STDOUT_FILENO, "Hello World");
	printf("----------------------------\n");
	printf("\n\e[4m  OPEN FILE DESCRIPTOR  \e[0m\n\n");
	file = "write_file.txt";
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	test(fd, "this string must be into this file");
	printf("\e[3m(check \"%s\" file)\e[0m\n", file);
	close(fd);
	printf("----------------------------\n");
	printf("\n\e[4m  WRONG FILE DESCRIPTOR  \e[0m\n\n");
	file = "error.txt";
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	test(fd + 5, "this string should not be into this file");
	printf("\e[3m(check \"%s\" file)\e[0m\n", file);
	close(fd);
}
