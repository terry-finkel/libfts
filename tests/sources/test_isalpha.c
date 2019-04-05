#include "tests.h"

int test_isalpha(int *nb)
{
	return (test_ctype(isalpha, ft_isalpha, nb));
}
