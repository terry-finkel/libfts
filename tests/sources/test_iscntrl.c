#include "tests.h"

int test_iscntrl(int *nb)
{
	return (test_ctype(iscntrl, ft_iscntrl, nb));
}
