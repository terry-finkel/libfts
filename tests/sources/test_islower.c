#include "tests.h"

int test_islower(int *nb)
{
	return (test_ctype(islower, ft_islower, nb));
}
