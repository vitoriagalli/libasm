/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:36:57 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/02 02:04:10 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void	test_ft_strlen(void)
{
	char *str;

	str = "Hello World";
	printf("\n\n\e[1;1m~~~~~~  FT_STRLEN  ~~~~~~\e[0m\n\n");
	printf("string    = \"%s\"\n\n", str);
	printf("strlen    = %lu, errno = %d\n", strlen(str), errno);
	printf("ft_strlen = %lu, errno = %d\n", ft_strlen(str), errno);
}

void	test_ft_strcpy()
{
	char	*ret;
	char	*src;
	char	dst[20];

	src = "Hello World";
	printf("\n\n\e[1;1m~~~~~~  FT_STRCPY  ~~~~~~\e[0m\n\n");
	printf("string    = \"%s\"\n\n", src);
	ret = strcpy(dst, src);
	printf("strcpy    = \"%s\"\n", ret);
	printf("return    = %p, errno = %d\n", ret, errno);
	bzero(dst, 5);
	ret = ft_strcpy(dst, src);
	printf("ft_strcpy = \"%s\"\n", ret);
	printf("return    = %p, errno = %d\n", ret, errno);
}

void	test_ft_strcmp(void)
{
	int		ret;
	char	*s1;
	char	*s2;

	s1 = "teste 1";
	s2 = "teste z";

	printf("\n\n\e[1;1m~~~~~~  FT_STRCMP  ~~~~~~\e[0m\n\n");
	printf("s1        = \"%s\"\n", s1);
	printf("s2        = \"%s\"\n\n", s2);
	ret = strcmp(s1, s2);
	printf("strcmp    = %d, errno = %d\n", ret, errno);
	ret = ft_strcmp(s1, s2);
	printf("ft_strcmp = %d, errno = %d\n", ret, errno);
}

void	test_ft_write(void)
{
	int		fd;
	char	*file;
	char	*str;
	int		ret;

	str = "Hello World";
	printf("\n\n\e[1;1m~~~~~~  FT_WRITE  ~~~~~~\e[0m\n");
	printf("\n\e[4m  STANDART OUTPUT  \e[0m\n\n");
	printf("string    = \"%s\"\n\n", str);
	ret = write(1, "write           = \"", 19);
	ret += write(1, str, ft_strlen(str));
	ret +=write(1, "\"\n", 2);
	printf("write errno     = %d\n", errno);
	printf("write return    = %d\n", ret);
	ret = ft_write(1, "ft_write        = \"", 19);
	ret += ft_write(1, str, ft_strlen(str));
	ret += ft_write(1, "\"\n", 2);
	printf("ft_write errno  = %d\n", errno);
	printf("ft_write return = %d\n", ret);

	file = "file.txt";
	printf("\n\e[4m  FILE DESCRIPTOR  \e[0m\n\n");
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	printf("string    = \"%s\"\n\n", str);
	write(fd, "write     = \"", 13);
	write(fd, str, ft_strlen(str));
	ret = write(fd, "\"\n", 2);
	printf("write errno     = %d\n", errno);
	printf("write return    = %d\n", ret);
	errno = 0;
	ft_write(fd, "ft_write   = \"", 14);
	ft_write(fd, str, ft_strlen(str));
	ret = ft_write(fd, "\"\n", 2);
	printf("ft_write errno  = %d\n", errno);
	printf("ft_write return = %d\n", ret);
	printf("\e[3m(check \"%s\" file)\e[0m\n", file);
	close(fd);
}

void	test_ft_read()
{
	int		fd;
	int		ret;
	char	buffer[101];
	char	*file;

	printf("\n\n\e[1;1m~~~~~~  FT_READ  ~~~~~~\e[0m\n");
	printf("\n\e[4m  STANDART INPUT  \e[0m\n\n");
	ret = read(0, buffer, 100);
	buffer[ret] = '\0';
	printf("read      = \"%s\"\n", buffer, errno);
	printf("return    = %d, errno = %d\n", ret, errno);
	ret = ft_read(0, buffer, 100);
	buffer[ret] = '\0';
	printf("ft_read   = \"%s\"\n", buffer, errno);
	printf("return    = %d, errno = %d\n", ret, errno);

	file = "file.txt";
	printf("\n\e[4m  FILE DESCRIPTOR  \e[0m\n\n");
	fd = open("file.txt", O_RDWR);
	ret = read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("read           =\n\"%s\"\n", buffer);
	printf("read errno     = %d\n", errno);
	printf("read return    = %d\n\n", ret);
	close(fd);
	bzero(buffer, 100);
	errno = 0;
	fd = open("file.txt", O_RDWR);
	ret = read(fd, buffer, 100);
	buffer[ret] = '\0';
	printf("ft_read        =\n\"%s\"\n", buffer);
	printf("ft_read erno   = %d\n", errno);
	printf("ft_read return = %d\n", ret);
	close(fd);

}

void	test_ft_strdup(void)
{
	char	*str;
	char	*ptr;

	str = "42 Sao Paulo - LIBASM";

	printf("\n\n\e[1;1m~~~~~~  FT_STRDUP  ~~~~~~\e[0m\n\n");
	printf("string    = \"%s\"\n\n", str);
	ptr = strdup(str);
	printf("strdup    = \"%s\"\n", ptr);
	printf("errno = %d\n", errno);
	free(ptr);
	ptr = ft_strdup(str);
	printf("ft_strdup = \"%s\"\n", ptr);
	printf("errno = %d\n", errno);
	free(ptr);
}

int		main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}
