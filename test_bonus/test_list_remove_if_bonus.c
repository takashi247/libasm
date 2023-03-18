/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:08:04 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/18 18:42:27 by tnishina         ###   ########.fr       */
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
	run_list_remove_if_tests(void)
{
	t_list	*head;
	t_list	*tmp;
	char	*str[3];

	head = NULL;
	str[0] = ft_strdup("100");
	str[1] = ft_strdup("200");
	str[2] = ft_strdup("300");
	ft_list_push_front(&head, str[0]);
	ft_list_push_front(&head, str[1]);
	ft_list_push_front(&head, str[2]);
	printf("%s***ft_list_push_front test***\n%s", BLUE, DEFAULT);
	printf("before remove_if: ");
	print_list(head);
	ft_list_remove_if(&head, "200", ft_strcmp, free);
	printf("after remove_if: ");
	print_list(head);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->data);
		free(tmp);
	}
}
