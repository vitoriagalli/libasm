/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 01:38:05 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/06 00:35:33 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include "libasm.h"
#include <stdio.h>

void	ft_print_list(t_list *list)
{
	t_list	*list_ptr;

	list_ptr = list;
	while (list_ptr)
	{
		printf("%s\n", (char*)(list_ptr->data));
		list_ptr = list_ptr->next;
	}
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

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
	print_ft_atoi_base(" +105", "0123456789");
	print_ft_atoi_base("  -+11", "01");
	printf("\e[3m(expected: error)\e[0m\n");
	print_ft_atoi_base("15256", "");				// empty base
	print_ft_atoi_base("15", "5");					// base w/ one char
	print_ft_atoi_base("122", "-123456789");		// base with sign
	print_ft_atoi_base("122", "012+3456789");		// base with sign
	print_ft_atoi_base("111", "0 1");				// base with space
	print_ft_atoi_base("568", "012345\t6789");		// base with space
	print_ft_atoi_base("111", "01\r");				// base with space
	print_ft_atoi_base("155", "01234506789");		// double char
	print_ft_atoi_base("05", "012345067890");		// double char
	print_ft_atoi_base("abc56", "0123456789");		// dont belong base
	print_ft_atoi_base(NULL, "0123456789");			// null pointer
	print_ft_atoi_base("501", NULL);				// null pointer
}

void	test_linked_list(void)
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "milk");
	ft_list_push_front(&list, "bread");
	ft_list_push_front(&list, "apple");
	printf("\n\e[1;1m~~~~~~  LINKED LIST  ~~~~~~\e[0m\n");
	printf("\n\e[3mLISTA ORIGINAL:  \e[0m\n");
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_PUSH_FRONT  \e[0m\n\n");
	ft_list_push_front(&list, "eggs");
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_SIZE  \e[0m\n\n");
	printf("list size = %i\n", ft_list_size(list));
	printf("\n\e[4m  FT_LIST_SORT  \e[0m\n\n");
	ft_list_sort(&list, ft_strcmp);
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_REMOVE_IF  \e[0m\n\n");
	ft_list_remove_if(&list, "milk", ft_strcmp, ft_free);
	ft_print_list(list);
}

int		main(void)
{
	test_ft_atoi_base();
	// test_linked_list();
	return (0);
}
