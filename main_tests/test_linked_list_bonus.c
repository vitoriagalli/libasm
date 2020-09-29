/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_linked_list_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 02:48:54 by vscabell          #+#    #+#             */
/*   Updated: 2020/09/24 15:31:29 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_main_bonus.h"
#include "libasm_bonus.h"
#include "libasm.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*aux;

	if (!begin_list || !free_fct)
		return ;
	while (begin_list)
	{
		aux = begin_list;
		begin_list = begin_list->next;
		(free_fct)(aux->data);
		free(aux);
	}
	begin_list = NULL;
}

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char*)(list->data));
		list = list->next;
	}
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	test_linked_list(void)
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, ft_strdup("milk"));
	ft_list_push_front(&list, ft_strdup("bread"));
	ft_list_push_front(&list, ft_strdup("apple"));
	printf("\n\e[1;1m~~~~~~  LINKED LIST  ~~~~~~\e[0m\n");
	printf("\n\e[3mORIGINAL LIST:  \e[0m\n");
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_PUSH_FRONT  \e[0m\n\n");
	ft_list_push_front(&list, ft_strdup("eggs"));
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_SIZE  \e[0m\n\n");
	printf("list size = %i\n", ft_list_size(list));
	printf("\n\e[4m  FT_LIST_SORT  \e[0m\n\n");
	ft_list_sort(&list, ft_strcmp);
	ft_print_list(list);
	printf("\n\e[4m  FT_LIST_REMOVE_IF  \e[0m\n\n");
	ft_list_remove_if(&list, "eggs", ft_strcmp, ft_free);
	ft_print_list(list);
	ft_list_clear(list, ft_free);
}
