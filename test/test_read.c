/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:57:19 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/13 23:58:28 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void
	test_read_error(void)
{
	char	buf[BUFSIZ];

	printf("read(-1, buf, 1):\n");
	read(-1, buf, 1);
	printf("\n%s\n", strerror(errno));
	printf("ft_read(-1, buf, 1):\n");
	ft_read(-1, buf, 1);
	printf("\n%s\n", strerror(errno));
	printf("read(1, buf, -1):\n");
	read(1, buf, -1);
	printf("\n%s\n", strerror(errno));
	printf("ft_read(1, buf, -1):\n");
	ft_read(1, buf, -1);
	printf("\n%s\n", strerror(errno));
}

static void
	test_read(void)
{
	char	buf[BUFSIZ];
	int		fildes;
	ssize_t	res_libc;
	ssize_t	res_ft;

	bzero(buf, BUFSIZ);
	fildes = open("Makefile", O_RDONLY);
	printf("read:\n");
	res_libc = read(fildes, buf, 100);
	printf("buf:\n%s\n", buf);
	printf("returned value: %zd\n", res_libc);
	close(fildes);
	bzero(buf, BUFSIZ);
	fildes = open("Makefile", O_RDONLY);
	printf("ft_read:\n");
	res_ft = ft_read(fildes, buf, 100);
	printf("buf:\n%s\n", buf);
	printf("returned value: %zd\n", res_ft);
	close(fildes);
	if (res_libc == res_ft)
		printf("result:\t%s%s%s\n", GREEN, "OK!", DEFAULT);
	else
		printf("result:\t%s%s%s\n", RED, "NG!", DEFAULT);
}

void
	run_read_tests(void)
{
	printf("%s***ft_read test***\n%s", BLUE, DEFAULT);
	test_read();
	printf("%s***ft_read error test***\n%s", BLUE, DEFAULT);
	test_read_error();
}
