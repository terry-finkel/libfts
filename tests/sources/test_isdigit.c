#include "tests.h"

int test_isdigit(int *nb)
{
	return (test_ctype(isdigit, ft_isdigit, nb));
}
