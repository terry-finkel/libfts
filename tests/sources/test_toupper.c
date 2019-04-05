#include "tests.h"

int test_toupper(int *nb)
{
	return (test_ctype(toupper, ft_toupper, nb));
}
