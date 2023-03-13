/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:34:32 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/14 00:19:17 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void
	test_strlen(const char *str)
{
	ssize_t	res_libc;
	ssize_t	res_ft;

	printf("str = %s:\n", str);
	res_libc = strlen(str);
	printf("strlen:\t\t%zu\n", res_libc);
	res_ft = ft_strlen(str);
	printf("ft_strlen:\t%zu\n", res_ft);
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
	run_strlen_tests(void)
{
	printf("%s***ft_strlen test***%s\n", BLUE, DEFAULT);
	test_strlen("42");
	test_strlen("hoge");
	test_strlen("");
	test_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}
