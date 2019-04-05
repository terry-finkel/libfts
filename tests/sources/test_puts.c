#include "tests.h"

static int unit_test(char *str, int fd)
{
	char buf[1024];
	size_t len = strlen(str);

	ft_puts(str);
	read(fd, buf, len + 1);
	if (strncmp(buf, str, len + 1) != '\n')
		return (0);
	return (1);
}

int test_puts(int *nb)
{
	char *str[] = {
		"hello world", "", "foobarbaz", "qwertyuiopasdfghjklzxcvbnm"
		"1234567890-=!@#$%^&*()_+[]\\|{};':\",./<>?",
		"echo toto       tata    ", "one last simple test..."
	};
	int failed = 0;
	int stdout = dup(1);
	int fildes[2];

	*nb = sizeof(str) / sizeof(str[0]);
	pipe(fildes);
	dup2(fildes[1], 1);
	for (int i = 0; i < *nb; i++) {
		if (unit_test(str[i], fildes[0]) == 0) {
			dup2(stdout, 1);
			printf("\nfailed test %d: \"%s\"", i, str[i]);
			failed++;
			dup2(fildes[1], 1);
		}
	}
	close(fildes[0]);
	close(fildes[1]);
	dup2(stdout, 1);
	return (failed);
}
