#include "tests.h"

int test_isspace(int *nb)
{
	return (test_ctype(isspace, ft_isspace, nb));
}
