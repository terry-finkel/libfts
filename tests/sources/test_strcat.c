#include "tests.h"

static int unit_test(const char *a, const char *b)
{
	char mine[1024];
	char real[1024];

	strcpy(mine, a);
	ft_strcat(mine, b);
	strcpy(real, a);
	strcat(real, b);
	return (!strcmp(mine, real));
}

int test_strcat(int *nb)
{
	char *a[] = {"a", "hello ", "", "qwertyuiopasdfghjklzxcvbnm"};
	char *b[] = {"b", "world!", "", "234567890[];'/.,`!@#$%^&*()_+"};
	size_t i, j;
	int failed = 0;

	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		for (j = 0; j < sizeof(b) / sizeof(b[0]); j++) {
			if (unit_test(a[i], b[j]) == 0) {
				printf("\nfailed test %zu: \"%s\"+\"%s\"",
				       i * sizeof(b) / sizeof(b[0])+ j,
				       a[i], b[j]);
				failed++;
			}
		}
	}
	*nb = i * j;
	return (failed);
}
