#include "tests.h"

static int unit_test(const char *dest, const char *src)
{
	char mine[1024];
	char real[1024];
	size_t dsize, ssize;

	dsize = strlen(dest);
	ssize = strlen(src);
	ft_memcpy(mine, dest, dsize);
	ft_memcpy(mine, src, ssize);
	memcpy(real, dest, dsize);
	memcpy(real, src, ssize);
	return (!(memcmp(mine, real, (dsize > ssize ? dsize : ssize))));
}

int test_memcpy(int *nb)
{
	static char *dest[] = {
		"", "hello ", "foo bar baz toto tata tutu"
	};
	static char *src[] = {
		"", "world!", "1234567890", "qwertyuiopasdfghjklzxcvbnm"
		"1234567890-=[]\\;',./`~!@#$%^&*()_+{}|L:\"<>?"
	};
	size_t i, j;
	int failed = 0;

	for (i = 0; i < sizeof(dest) / sizeof(dest[0]); i++) {
		for (j = 0; j < sizeof(src) / sizeof(src[0]); j++) {
			if (unit_test(dest[i], src[j]) == 0) {
				printf("\nfailed test %zu: \"%s\", \"%s\"",
				       i * sizeof(src) / sizeof(src[0]) + j,
				       dest[i], src[j]);
				failed++;
			}
		}
	}
	*nb = i * j;
	return (failed);
}
