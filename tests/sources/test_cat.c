#include "tests.h"

#define RM(file) (system("rm -f " file))

static int unit_test(const char *file)
{
	char cmd[128];
	int stdout = dup(1);
	int out = open(CAT_OUT, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	int fd = open(file, O_RDONLY);

	if (stdout < 0 || out < 0 || fd < 0) {
		printf("\nWARNING: unable to manipulate file descriptors");
		return (0);
	}
	dup2(out, 1);
	ft_cat(fd);
	close(fd);
	close(out);
	dup2(stdout, 1);
	strcpy(cmd, "diff >> " CAT_DIF " " CAT_OUT " ");
	strcat(cmd, file);
	return (!system(cmd));
}

int test_cat(int *nb)
{
	char *file[] = {
		"/usr/include/kern/kern_cdata.h",
		"/usr/include/ldap.h",
		"/usr/include/malloc/malloc.h",
		"/bin/ls",
		"/usr/bin/audiodevice"
	};
	int failed = 0;
	
	RM(CAT_DIF);
	*nb = sizeof(file) / sizeof(file[0]);
	for (int i = 0; i < *nb; i++) {
		if (unit_test(file[i]) == 0) {
			printf("\nfailed test %d: \"%s\"", i, file[i]);
			failed++;
		}
	}
	RM(CAT_OUT);
	if (failed)
		printf("\n(diff logged in \"" CAT_DIF "\")");
	else
		RM(CAT_DIF);
	return (failed);
}
