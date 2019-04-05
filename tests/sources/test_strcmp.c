#include "tests.h"

static int unit_test(const char *s1, const char *s2)
{
	return (strcmp(s1, s2) == ft_strcmp(s1, s2));
}

int test_strcmp(int *nb)
{
	static char *s[] = {
		"",
		"hello world",
		"foo bar",
		"hello",
		"!@#$%^&*()",
		"abcdef",
		"abcdefg",
		"f"
	};
	int failed = 0;

	*nb = sizeof(s) / sizeof(*s);
	for (int i = 0; i < *nb; i++) {
		for (int j = 0; j < *nb; j++) {
			if (unit_test(s[i], s[j]) == 0) {
				printf("\nfailed test %d: \"%s\", \"%s\"",
				       i * *nb + j, s[i], s[j]);
				failed++;
			}
		}
	}
	*nb *= *nb;
	return (failed);
}
