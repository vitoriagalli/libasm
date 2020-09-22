/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:00:03 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/20 03:46:56 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test(char *str)
{
	printf("string    = \"%s\"\n\n", str);
	printf("strlen    = %lu\n", strlen(str));
	printf("ft_strlen = %lu\n", ft_strlen(str));
	printf("----------------------------\n");
}

void		test_ft_strlen(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRLEN  ~~~~~~\e[0m\n\n");
	test("Hello World");
	test("\ttesting ft_strlen");
	test("");
	test("a very very very very very very very very very very long string");
	test("abcdef\0---34567");
	test("   ");
}
