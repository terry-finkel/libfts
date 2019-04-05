#include "tests.h"

static int unit_test(int size)
{
	char buf[4096];

	memset(buf, '*', size);
	ft_bzero(buf, size);
	for (int i = 0; i < size; i++) {
		if (buf[i])
			return (0);
	}
	return (1);
}

int test_bzero(int *nb)
{
	static int size[] = {
		0, 1, 8, 10, 245, 42, 64, 100, 129, 1000, 76, 928, 1023, 2048,
		3000, 666
	};
	int failed = 0;

	*nb = sizeof(size) / sizeof(size[0]);
	for (int i = 0; i < *nb; i++) {
		if (unit_test(size[i]) == 0) {
			printf("\nfailed test %d: size = %d", i, size[i]);
			failed++;
		}
	}
	return (failed);
}
