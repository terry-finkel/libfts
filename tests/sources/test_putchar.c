#include "tests.h"

static int unit_test(char c, int fd)
{
	char buf[1];
	
	ft_putchar(c);
	read(fd, buf, 1);
	return (*buf == c);
}

int test_putchar(int *nb)
{
	static char chr[] = {
		'a', '*', '\n', 10, 1, 0, 'A', 127, 0xff, -1, '.'
	};
	int failed = 0;
	int stdout = dup(1);
	int fildes[2];

	*nb = sizeof(chr) / sizeof(chr[0]);
	pipe(fildes);
	dup2(fildes[1], 1);
	for (int i = 0; i < *nb; i++) {
		if (unit_test(chr[i], fildes[0]) == 0) {
			dup2(stdout, 1);
			printf("\nfailed test %d: \"%c\"", i, chr[i]);
			failed++;
			dup2(fildes[1], 1);
		}
	}
	close(fildes[0]);
	close(fildes[1]);
	dup2(stdout, 1);
	return (failed);
}
