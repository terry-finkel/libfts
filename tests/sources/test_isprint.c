#include "tests.h"

int test_isprint(int *nb)
{
	return (test_ctype(isprint, ft_isprint, nb));
}
