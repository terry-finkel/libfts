#include "libft.h"
#include <string.h>
#include <stdio.h>


#define FT_BZERO_TEST   true
#define FT_PUTS_TEST    true
#define FT_STRLEN_TEST  true

const char 		*test_string = "Le caca c'est bien mais le miel c'est quand meme beaucoup mieux...";

int     main(int argc, char *argv[]) {
	bool 			success;
	const size_t	test_string_len = strlen(test_string);
	char 			*str = (char *)malloc(sizeof(char) * test_string_len + 1);
	printf("Buffering test string in memory...\n");
	snprintf(str, test_string_len + 1, "%s", test_string);

#if FT_BZERO_TEST == true
	success = true;
	printf("\nStarting test for ft_bzero...\n");
	ft_bzero(str, test_string_len);
	for (unsigned int k = 0; k < test_string_len; k++) {
		if (str[k] != 0) {
			success = false;
			break;
		}
	}
	printf(" - ft_bzero, status: %s\n", success ? "SUCCESS" : "FAIL");
#endif

#if FT_PUTS_TEST == true
    snprintf(str, test_string_len + 1, "%s", test_string);
    printf("\nStarting test for ft_puts...\n");
	printf(" - Test string: \'%s\'\n - Output using puts: ", str);
	int ret_value = puts(str);
	printf(" - Return value with puts: %d\n", ret_value);
	dprintf(STDOUT_FILENO, " - Output using ft_puts: ");
	ret_value = ft_puts(str);
    printf(" - Return value with ft_puts: %d\n", ret_value);
#endif

#if FT_STRLEN_TEST == true
    printf("\nStarting test for ft_strlen...\n - Test string: %s\n", str);
    printf(" - String length using strlen: %lu\n", test_string_len);
    printf(" - String length using ft_strlen: %lu\n", ft_strlen(test_string));
#endif
}