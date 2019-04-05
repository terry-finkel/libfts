#include "tests.h"

int test_isalnum(int *nb)
{
	return (test_ctype(isalnum, ft_isalnum, nb));
}
