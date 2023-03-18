/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:26:44 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/18 09:37:41 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

static void
	print_list_size(t_list *begin_list)
{
	int	size;

	size = ft_list_size(begin_list);
	printf("list size: %d\n", size);
}

void
	run_list_size_tests(void)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	ft_list_push_front(&head, "first");
	ft_list_push_front(&head, "second");
	ft_list_push_front(&head, "third");
	printf("%s***ft_list_size test***\n%s", BLUE, DEFAULT);
	print_list_size(head);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
}
