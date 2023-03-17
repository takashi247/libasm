/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:26:44 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/17 23:36:44 by tnishina         ###   ########.fr       */
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
	run_list_push_front_tests(void)
{
	t_list*	head;
	t_list*	tmp;

	head = NULL;
	ft_list_push_front(&head, "first");
	ft_list_push_front(&head, "second");
	ft_list_push_front(&head, "third");
	printf("%s***ft_list_push_front test***\n%s", BLUE, DEFAULT);
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
