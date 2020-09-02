/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 01:38:05 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/02 03:28:37 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include "libasm.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_make_list(t_list **list, void **str, int size)
{
	t_list *tmp;
	int		i;

	i = 0;
	if (!(*list) || !(list))
	{
		*list = ft_create_elem(str[i]);
		i++;
	}
	while (i < size)
	{
		tmp = ft_create_elem(str[i]);
		tmp->next = *list;
		*list = tmp;
		i++;
	}
}

void 	ft_print_list(t_list *list)
{
	t_list	*list_ptr;

	list_ptr = list;
	while (list_ptr)
	{
		printf("%s\n", (char*)(list_ptr->data));
		list_ptr =  list_ptr->next;
	}
}

void	ft_free(void *ptr)
{
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
}

void	test_linked_list(void)
{
	char *arr[] = {"terceiro", "segundo", "primeiro", 0};
	t_list	*list;

	list = NULL;
	ft_make_list(&list, (void **)arr, 3);
	printf("\n\e[1;1m~~~~~~  LINKED LIST  ~~~~~~\e[0m\n");
	printf("\n\e[3mLISTA ORIGINAL:  \e[0m\n");
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_PUSH_FRONT  \e[0m\n\n");
	ft_list_push_front(&list, "test");
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_SIZE  \e[0m\n\n");
	printf("list size = %i\n", ft_list_size(list));
	printf("\n\e[4m  FT_LIST_SORT  \e[0m\n\n");
	ft_list_sort(&list, ft_strcmp);
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_REMOVE_IF  \e[0m\n\n");
	ft_list_remove_if(&list, "test", ft_strcmp, ft_free);
	ft_print_list(list);
}

int		main(void)
{
	test_ft_atoi_base();
	test_linked_list();
}
