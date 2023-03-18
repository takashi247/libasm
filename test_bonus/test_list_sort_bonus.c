/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:08:04 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/18 14:12:31 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

static void
	print_list(t_list *begin_list)
{
	while (begin_list)
	{
		printf("%s", begin_list->data);
		if (begin_list->next)
			printf(" -> ");
		else
			printf("\n");
		begin_list = begin_list->next;
	}
}

void
	run_list_sort_tests(void)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	ft_list_push_front(&head, "100");
	ft_list_push_front(&head, "200");
	ft_list_push_front(&head, "300");
	printf("%s***ft_list_push_front test***\n%s", BLUE, DEFAULT);
	printf("before sort: ");
	print_list(head);
	ft_list_sort(&head, ft_strcmp);
	printf("after sort: ");
	print_list(head);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
}
