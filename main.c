#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "libasm.h"

extern int errno;

void
	test_write_error()
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

void
	test_write(int fildes, const char *str)
{
	printf("str = %s:\n", str);
	printf("write:\n");
	const ssize_t res_libc = write(fildes, str, strlen(str));
	printf("\nreturned value: %zd\n", res_libc);
	printf("ft_write:\n");
	const ssize_t res_ft = ft_write(fildes, str, strlen(str));
	printf("\nreturned value: %zd\n", res_ft);
	if (res_libc == res_ft) {
		printf("result:\t%s", GREEN);
		printf("%s%s\n", "OK!", DEFAULT);
	} else {
		printf("result:\t%s", RED);
		printf("%s%s\n", "NG!", DEFAULT);
	}
}

void
	test_strcmp(const char *s1, const char *s2)
{
	printf("s1 = %s, s2 = %s:\n", s1, s2);
	const int res_libc = strcmp(s1, s2);
	printf("strcmp:\t\t%d\n", res_libc);
	const int res_ft = ft_strcmp(s1, s2);
	printf("ft_strcmp:\t%d\n", res_ft);
	if (res_libc == res_ft) {
		printf("result:\t%s", GREEN);
		printf("%s%s\n", "OK!", DEFAULT);
	} else {
		printf("result:\t%s", RED);
		printf("%s%s\n", "NG!", DEFAULT);
	}
}

void
	test_strcpy(const char *str)
{
	char	dest_libc[100];
	char	dest_ft[100];

	printf("str = %s:\n", str);
	const char* res_libc = strcpy(dest_libc, str);
	printf("strcpy:\t\t%s\n", res_libc);
	const char* res_ft = ft_strcpy(dest_ft, str);
	printf("ft_strcpy:\t%s\n", res_ft);
	if (!strcmp(res_libc, res_ft)) {
		printf("result:\t%s", GREEN);
		printf("%s%s\n", "OK!", DEFAULT);
	} else {
		printf("result:\t%s", RED);
		printf("%s%s\n", "NG!", DEFAULT);
	}
}

void
	test_strlen(const char* str)
{
	printf("str = %s:\n", str);
	const size_t res_libc = strlen(str);
	printf("strlen:\t\t%zu\n", res_libc);
	const size_t res_ft = ft_strlen(str);
	printf("ft_strlen:\t%zu\n", res_ft);
	if (res_libc == res_ft) {
		printf("result:\t%s", GREEN);
		printf("%s%s\n", "OK!", DEFAULT);
	} else {
		printf("result:\t%s", RED);
		printf("%s%s\n", "NG!", DEFAULT);
	}
}

int
	main(void)
{
	printf("%s***ft_strlen test***%s\n", BLUE, DEFAULT);
  test_strlen("42");
	test_strlen("hoge");
	test_strlen("");
	test_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("%s***ft_strcpy test***\n%s", BLUE, DEFAULT);
	test_strcpy("42");
	test_strcpy("hoge");
	test_strcpy("");
	test_strcpy("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	test_strcpy("42");
	printf("%s***ft_strcmp test***\n%s", BLUE, DEFAULT);
	test_strcmp("42", "42");
	test_strcmp("hoge", "hoga");
	test_strcmp("", " ");
	test_strcmp("fuga", "fugaaaaaaaaaaaaaaaa");
	printf("%s***ft_write test***\n%s", BLUE, DEFAULT);
	test_write(STDOUT_FILENO, "42");
	test_write(STDOUT_FILENO, "hoge");
	test_write(STDOUT_FILENO, "");
	test_write(STDOUT_FILENO, "123456789");
	test_write(STDOUT_FILENO, "0123456789");
	test_write(STDOUT_FILENO, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("%s***ft_write error test***\n%s", BLUE, DEFAULT);
	test_write_error();
	return (0);
}
