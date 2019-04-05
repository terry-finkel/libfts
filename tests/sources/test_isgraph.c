#include "tests.h"

int test_isgraph(int *nb)
{
	return (test_ctype(isgraph, ft_isgraph, nb));
}
