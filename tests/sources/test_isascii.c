#include "tests.h"

int test_isascii(int *nb)
{
	return (test_ctype(isascii, ft_isascii, nb));
}
