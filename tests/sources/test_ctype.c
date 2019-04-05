#include "tests.h"

int test_ctype(int (*real)(int), int (*mine)(int), int *nb)
{
	int failed = 0;

	*nb = CTYPE_TEST_MAX - CTYPE_TEST_MIN;
	for (int i = CTYPE_TEST_MIN; i < CTYPE_TEST_MAX; i++) {
		if (!real(i) != !mine(i)) {
			printf("\nfailed test %d: %d '%c' -> %d vs %d",
			       i - CTYPE_TEST_MIN, i, (isprint(i) ? i : 0),
			       real(i), mine(i));
			failed++;
		}
	}
	return (failed);
}
