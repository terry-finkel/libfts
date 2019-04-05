#include "tests.h"

int test_isupper(int *nb)
{
	return (test_ctype(isupper, ft_isupper, nb));
}
