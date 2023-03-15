/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:53:01 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/15 20:07:07 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

static void
	test_strchr(const char *s, int c)
{
	char	*res_libc;
	char	*res_ft;

	printf("s = %s, c = %d:\n", s, c);
	res_libc = strchr(s, c);
	printf("strchr:\t\t%s\n", res_libc);
	res_ft = ft_strchr(s, c);
	printf("ft_strchr:\t%s\n", res_ft);
	if (((!res_libc) && (!res_ft))
		|| (res_libc && res_ft && (!strcmp(res_libc, res_ft))))
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
	run_strchr_tests(void)
{
	printf("%s***ft_strchr test***\n%s", BLUE, DEFAULT);
	test_strchr("42", '2');
	test_strchr("hoge", 'g');
	test_strchr("", ' ');
	test_strchr("fuga", 'h');
}
