#include "tests.h"

static int unit_test(char *str)
{
	if (ft_strlen(str) != strlen(str))
		return (0);
	return (1);
}

int test_strlen(int *nb)
{
	static char *str[] = {
		"hello world", "", "foobarbaz", "12345678", "1234567",
		"123456789", "qwertyuiopasdfgjlzxcvbnm",
		"dslh ads l3;ku68459y9uwqio fsaf h;oiuwr qwro  fwtyturwe56 tsad"
		"asfdgrgjiu1 2y23405 sjhf alsdkfh hph fq398y osladfjk lkajsdf",
		"1234567890123456", "123456789012345", "12345678901234567"
	};
	int failed = 0;

	*nb = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < *nb; i++) {
		if (unit_test(str[i]) == 0) {
			printf("\nfailed test %d: \"%s\"", i, str[i]);
			failed++;
		}
	}
	return (failed);
}
