#include <stdio.h>
#include "libasm.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%zu\n", ft_strlen(av[1]));
	}
}
