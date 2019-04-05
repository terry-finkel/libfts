#include "tests.h"

static int unit_test(const void *s, int c, size_t n)
{
	return (ft_memchr(s, c, n) == memchr(s, c, n));
}

int test_memchr(int *nb)
{
	static void *str[] = {
		"",
		"hello world",
		"!@#$%^&*()1234567890QWERTYUIOPqweuiopASDFGHJKLashjkl"
		"ZXCVBNMzxcvbnm",
	};
	int arr[] = {
		0, 1, 2, 8, 9, 10, 100, 2048, 21, 42, 84, 1024, 65, 'q', 'z'
	};
	static int chr[] = {
		0, 42, 'A', -1, 1000, 'o', 'q', '!'
	};
	size_t i, j;
	int failed = 0;

	for (i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		for (j = 0; j < sizeof(chr) / sizeof(chr[0]); j++) {
			if (unit_test(str[i], chr[j], strlen(str[i])) == 0) {
				printf("\nfailed test %zu: \"%s\" '%d'",
				       i * (sizeof(chr) / sizeof(chr[0])) + j,
				       str[i], chr[j]);
				failed++;
			}
		}
	}
	*nb = i * j;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (j = 0; j < sizeof(chr) / sizeof(chr[0]); j++) {
			if (unit_test(arr + i, chr[j],
				      sizeof(arr) - i * sizeof(arr[0])) == 0) {
				printf("\nfailed test %zu: (%zu, %zu)",
				       *nb + i * (sizeof(chr) / sizeof(chr[0]))
				       + j, i, j);
				failed++;
			}
		}
	}
	*nb += i * j;
	return (failed);
}
