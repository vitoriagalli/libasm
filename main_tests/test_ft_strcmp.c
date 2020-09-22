/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:00:14 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/20 03:46:03 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test(char *s1, char *s2)
{
	printf("s1        = \"%s\"\n", s1);
	printf("s2        = \"%s\"\n\n", s2);
	printf("strcmp    = %d\n", strcmp(s1, s2));
	printf("ft_strcmp = %d\n", ft_strcmp(s1, s2));
	printf("----------------------------\n");
}

void		test_ft_strcmp(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRCMP  ~~~~~~\e[0m\n\n");
	test("Hello World", "");
	test("", "Hello World");
	test("", "");
	test("test\ting", "test\ving");
	test("1234\0p1234", "1234\0abcdef");
}
