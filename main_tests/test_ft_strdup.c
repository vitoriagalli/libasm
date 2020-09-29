/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 01:00:06 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/25 14:30:03 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main.h"
#include "libasm.h"

static void	test(char *str)
{
	char	*ptr;

	ptr = NULL;
	printf("ptr value       = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	ptr = strdup(str);
	printf("strdup          = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	printf("strdup errno    = %d\n\n", errno);
	free(ptr);
	errno = 0;
	ptr = NULL;
	printf("ptr value       = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	ptr = ft_strdup(str);
	printf("ft_strdup       = \"%s\"\n", ptr);
	printf("ptr addr        = %p\n", ptr);
	printf("ft_strdup errno = %d\n\n", errno);
	free(ptr);
	errno = 0;
	printf("----------------------------\n");
}

void		test_ft_strdup(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_STRDUP  ~~~~~~\e[0m\n\n");
	test("42 Sao Paulo - LIBASM");
	test("testing ft_strdup");
}
