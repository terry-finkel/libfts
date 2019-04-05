#include "tests.h"

static int unit_test(int size, int c)
{
	char mine[4096];
	char real[4096];

	ft_memset(mine, c, size);
	ft_memset(real, c, size);
	return (!memcmp(mine, real, size));
}

int test_memset(int *nb)
{
	static int c[] = {
		0, '*', -1, 'a', 127, 256, 1000
	};
	static int size[] = {
		0, 345, 547, 5, 2, 24, 457, 65, 87, 8, 3457, 1024, 2048,
		3000, 473, 1033, 65, 55
	};
	size_t i, j;
	int failed = 0;

	for (i = 0; i < sizeof(c) / sizeof(c[0]); i++) {
		for (j = 0; j < sizeof(size) / sizeof(size[0]); j++) {
			if (unit_test(size[i], c[j]) == 0) {
				printf("\nfailed test %zu: '%d' * %d",
				       i * sizeof(size) / sizeof(size[0]) + j,
				       c[i], size[j]);
				failed++;
			}
		}
	}
	*nb = i * j;
	return (failed);
}
