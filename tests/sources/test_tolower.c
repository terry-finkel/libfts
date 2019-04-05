#include "tests.h"

int test_tolower(int *nb)
{
	return (test_ctype(tolower, ft_tolower, nb));
}
