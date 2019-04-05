#include "tests.h"

#define MIN(a, b) (a < b ? a : b)

static int unit_test(const void *s1, const void *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n));
}

int test_memcmp(int *nb)
{
	static char *s1[] = {
		"hello world",
		"foooooooo",
		"",
		"a",
		"!@#$%^&*()"
	};
	static char *s2[] = {
		"hello world",
		"foo",
		"",
		"b",
		"hellow",
		"!@#$%^&()"
	};
	static int n1[][42] = {
		{1234, 2, 3, 42, 0, 66, 7},
		{'*', 42}
	};
	static int n2[][42] = {
		{1234, 2, 3, 42, 0, 66, 7, 8},
		{1234, 2, 3, 42},
		{42, '*', 0},
		{1234, 2, 3, 42, 5, 66}
	};
	size_t i, j;
	int failed = 0;

	for (i = 0; i < sizeof(s1) / sizeof(*s1); i++) {
		for (j = 0; j < sizeof(s2) / sizeof(*s2); j++) {
			if (unit_test(s1[i], s2[j],
				      MIN(strlen(s1[i]), strlen(s2[j]))) == 0) {
				printf("\nfailed test %zu: \"%s\", \"%s\"",
				       i * sizeof(s2) / sizeof(*s2) + j,
				       s1[i], s2[j]);
				failed++;
			}
		}
	}
	*nb = i * j;
	for (i = 0; i < sizeof(n1) / sizeof(*s1); i++) {
		for (j = 0; j < sizeof(n2) / sizeof(*n2); j++) {
			if (unit_test(n1[i], n2[j],
				      MIN(sizeof(n1), sizeof(n2))) == 0) {
				printf("\nfailed test %zu: (%zu, %zu)",
				       *nb + i * sizeof(n2) / sizeof(*n2) + j,
				       i, j);
				failed++;
			}
		}
	}
	*nb += i * j;
	return (failed);	
}
