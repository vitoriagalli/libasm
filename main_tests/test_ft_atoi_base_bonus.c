/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:48:57 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/20 03:10:22 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main_bonus.h"
#include "libasm_bonus.h"

void	print_ft_atoi_base(char *str, char *base)
{
	printf("string: %s, base: %s\n", str, base);
	printf("ft_atoi_base: %i\n\n", ft_atoi_base(str, base));
}

void	test_ft_atoi_base(void)
{
	printf("\n\n\e[1;1m~~~~~~  FT_ATOI_BASE  ~~~~~~\e[0m\n\n");
	print_ft_atoi_base(" +--56", "0123456789");
	print_ft_atoi_base("	---ff", "0123456789abcdef");
	print_ft_atoi_base("\v-42", "0123456789");
	print_ft_atoi_base("\f+-+-11101", "01");
	print_ft_atoi_base("  -+00501", "0123456789");
	print_ft_atoi_base(" +105", "0123456789");
	print_ft_atoi_base("  -+11", "01");
	printf("\e[3m\n____(expected: error)____\e[0m\n\n");
	print_ft_atoi_base("15256", "");
	print_ft_atoi_base("15", "5");
	print_ft_atoi_base("122", "-123456789");
	print_ft_atoi_base("122", "012+3456789");
	print_ft_atoi_base("111", "0 1");
	print_ft_atoi_base("568", "012345\t6789");
	print_ft_atoi_base("111", "01\r");
	print_ft_atoi_base("155", "01234506789");
	print_ft_atoi_base("05", "012345067890");
	print_ft_atoi_base("abc56", "0123456789");
	print_ft_atoi_base(NULL, "0123456789");
	print_ft_atoi_base("501", NULL);
}
