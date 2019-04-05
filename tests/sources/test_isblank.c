#include "tests.h"

int test_isblank(int *nb)
{
	return (test_ctype(isblank, ft_isblank, nb));
}
