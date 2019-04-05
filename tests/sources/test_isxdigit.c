#include "tests.h"

int test_isxdigit(int *nb)
{
	return (test_ctype(isxdigit, ft_isxdigit, nb));
}
