#include "tests.h"

int test_ispunct(int *nb)
{
	return (test_ctype(ispunct, ft_ispunct, nb));
}
