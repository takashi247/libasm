#include <stdio.h>
#include <string.h>
#include "libasm.h"

void
	test_strcpy(const char* str)
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
	printf("***ft_strlen test***\n");
  test_strlen("42");
	test_strlen("hoge");
	test_strlen("");
	test_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("***ft_strcpy test***\n");
	test_strcpy("42");
	test_strcpy("hoge");
	test_strcpy("");
	test_strcpy("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	return (0);
}
