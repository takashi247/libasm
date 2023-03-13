/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:39:23 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/13 23:53:43 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void
	test_strcpy(const char *str)
{
	char	*res_libc;
	char	*res_ft;
	char	dest_libc[100];
	char	dest_ft[100];

	printf("str = %s:\n", str);
	res_libc = strcpy(dest_libc, str);
	printf("strcpy:\t\t%s\n", res_libc);
	res_ft = ft_strcpy(dest_ft, str);
	printf("ft_strcpy:\t%s\n", res_ft);
	if (!strcmp(res_libc, res_ft))
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
	run_strcpy_tests(void)
{
	printf("%s***ft_strcpy test***\n%s", BLUE, DEFAULT);
	test_strcpy("42");
	test_strcpy("hoge");
	test_strcpy("");
	test_strcpy("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}
