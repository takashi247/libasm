/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:54:50 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/13 23:56:20 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void
	test_write_error(void)
{
	printf("write(-1, \"1\", 1):\n");
	write(-1, "1", 1);
	printf("\n%s\n", strerror(errno));
	printf("ft_write(-1, \"1\", 1):\n");
	ft_write(-1, "1", 1);
	printf("\n%s\n", strerror(errno));
	printf("write(1, \"1\", -1):\n");
	write(1, "1", -1);
	printf("\n%s\n", strerror(errno));
	printf("ft_write(1, \"1\", -1):\n");
	ft_write(1, "1", -1);
	printf("\n%s\n", strerror(errno));
}

static void
	test_write(const char *str)
{
	ssize_t	res_libc;
	ssize_t	res_ft;

	printf("str = %s:\n", str);
	printf("write:\n");
	res_libc = write(STDOUT_FILENO, str, strlen(str));
	printf("\nreturned value: %zd\n", res_libc);
	printf("ft_write:\n");
	res_ft = ft_write(STDOUT_FILENO, str, strlen(str));
	printf("\nreturned value: %zd\n", res_ft);
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
	run_write_tests(void)
{
	printf("%s***ft_write test***\n%s", BLUE, DEFAULT);
	test_write("42");
	test_write("hoge");
	test_write("");
	test_write("123456789");
	test_write("0123456789");
	test_write("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("%s***ft_write error test***\n%s", BLUE, DEFAULT);
	test_write_error();
}
