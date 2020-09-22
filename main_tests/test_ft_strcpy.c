/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:00:09 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/20 03:41:06 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test(char *src)
{
	char	dst[100];

	printf("src       = \"%s\"\n\n", src);
	printf("dst value = \"%s\"\n", dst);
	printf("dst addr  = %p\n", dst);
	printf("strcpy    = \"%s\"\n", strcpy(dst, src));
	printf("return    = %p\n\n", dst);
	bzero(dst, 5);
	printf("dst value = \"%s\"\n", dst);
	printf("dst addr  = %p\n", dst);
	printf("strcpy    = \"%s\"\n", ft_strcpy(dst, src));
	printf("return    = %p\n\n", dst);
	bzero(dst, 5);
	printf("----------------------------\n");
}

void		test_ft_strcpy(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRCPY  ~~~~~~\e[0m\n\n");
	test("Hello World");
	test("");
	test("a very very very very very very very very very very long string");
	test("abcdef\0---34567");
}
