/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:48:43 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/17 18:58:41 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

static void
	test_atoi(char *str)
{
	int	res_libc;
	int	res_ft;

	printf("str = %s, base = 0123456789:\n", str);
	res_libc = atoi(str);
	printf("atoi:\t\t%d\n", res_libc);
	res_ft = ft_atoi_base(str, "0123456789");
	printf("ft_atoi_base:\t%d\n", res_ft);
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

static void
	test_atoi_base(char *str, char *base)
{
	int	res;

	printf("str = %s, base = %s:\n", str, base);
	res = ft_atoi_base(str, base);
	printf("ft_atoi_base: %d\n", res);
}

void
	run_atoi_base_tests(void)
{
	printf("%s***ft_atoi_base test***\n%s", BLUE, DEFAULT);
	test_atoi("42");
	test_atoi("100");
	test_atoi("       +42");
	test_atoi("       -   42");
	test_atoi("--");
	test_atoi("   ---+--+1234ab567");
	test_atoi("2147483647");
	test_atoi("-2147483648");
	test_atoi("2147483648");
	test_atoi("-2147483649");
	test_atoi("9999999999");
	test_atoi_base("42", "0123456789abcdef");
	test_atoi_base("2b", "0123456789abcdef");
	test_atoi_base("ff", "0123456789abcdef");
	test_atoi_base("42", "hoge");
	test_atoi_base("42", "");
	test_atoi_base("42", "fugaaaaaa");
	test_atoi_base("42", "@");
	test_atoi_base("42", "12345+");
	test_atoi_base("42", "1234-5");
	test_atoi_base("42", "1234 5");
	test_atoi_base("     +42", "hoge");
	test_atoi_base("     -42", "01234");
}
