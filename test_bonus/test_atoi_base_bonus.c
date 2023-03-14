/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:48:43 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/14 18:40:24 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

static void
	test_atoi_base(char *str, char *base)
{
	printf("str = %s, base = %s:\n", str, base);
	printf("ft_atoi_base: %d\n", ft_atoi_base(str, base));
}

void
	run_atoi_base_tests(void)
{
	printf("%s***ft_atoi_base test***\n%s", BLUE, DEFAULT);
	test_atoi_base("42", "0123456789");
	test_atoi_base("42", "hoge");
	test_atoi_base("42", "");
	test_atoi_base("42", "fugaaaaaa");
	test_atoi_base("42", "@");
}
