/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:53:01 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/13 23:54:13 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void
	test_strcmp(const char *s1, const char *s2)
{
	int	res_libc;
	int	res_ft;

	printf("s1 = %s, s2 = %s:\n", s1, s2);
	res_libc = strcmp(s1, s2);
	printf("strcmp:\t\t%d\n", res_libc);
	res_ft = ft_strcmp(s1, s2);
	printf("ft_strcmp:\t%d\n", res_ft);
	if (res_libc == res_ft)
	{
		printf("result:\t%s", GREEN);
		printf("%s%s\n", "OK!", DEFAULT);
	}
	else
	{
		printf("result:\t%s", RED);
		printf("%s%s\n", "NG!", DEFAULT);
	}
}

void
	run_strcmp_tests(void)
{
	printf("%s***ft_strcmp test***\n%s", BLUE, DEFAULT);
	test_strcmp("42", "42");
	test_strcmp("hoge", "hoga");
	test_strcmp("", " ");
	test_strcmp("fuga", "fugaaaaaaaaaaaaaaaa");
}
