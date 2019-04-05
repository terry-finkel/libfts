#include "tests.h"

static int unit_test(const char *str, int c)
{
	return (ft_strchr(str, c) == strchr(str, c));
}

int test_strchr(int *nb)
{
	static char *str[] = {
		"",
		"hello world",
		"foobarbaz",
		"qwertyuiopasfghjklzxcvbnm1234567890",
		"!@#$%^&*()1234567890QWERTYUIOPqweuiopASDFGHJKLashjkl"
		"ZXCVBNMzxcvbnm"
	};
	static int chr[] = {
		0, 42, 'A', -1, 1000, 'o', 'q', '!'
	};
	size_t i, j;
	int failed = 0;

	for (i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		for (j = 0; j < sizeof(chr) / sizeof(chr[0]); j++) {
			if (unit_test(str[i], chr[j]) == 0) {
				printf("\nfailed test %zu: \"%s\", '%d'",
				       i * (sizeof(chr) / sizeof(chr[0])) + j,
				       str[i], chr[j]);
				failed++;
			}
		}
	}
	*nb = i * j;
	return (failed);
}
