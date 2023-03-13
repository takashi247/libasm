/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:58:57 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/13 23:59:57 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void
	test_strdup(const char *str)
{
	char	*cpy_libc;
	char	*cpy_ft;

	printf("str = %s:\n", str);
	cpy_libc = strdup(str);
	printf("strdup:\t\t%s\n", cpy_libc);
	cpy_ft = ft_strdup(str);
	printf("ft_strdup:\t%s\n", cpy_ft);
	if (!strcmp(cpy_libc, cpy_ft))
	{
		printf("result:\t%s", GREEN);
		printf("%s%s\n", "OK!", DEFAULT);
	}
	else
	{
		printf("result:\t%s", RED);
		printf("%s%s\n", "NG!", DEFAULT);
	}
	free(cpy_libc);
	cpy_libc = NULL;
	free(cpy_ft);
	cpy_ft = NULL;
}

void
	run_strdup_tests(void)
{
	printf("%s***ft_strdup test***\n%s", BLUE, DEFAULT);
	test_strdup("42");
	test_strdup("hoge");
	test_strdup("");
	test_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}
