#include "libfts.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define FT_BZERO_TEST   true
#define FT_STRCAT_TEST  true
#define FT_PUTS_TEST    true
#define FT_STRLEN_TEST  true

const char 		*__ft_bzero_str__ = "Le caca c'est bien mais le miel c'est quand meme beaucoup mieux...";
const char      *__empty_string__ = "";
const char      *__ft_strcat_str_1__ = "Le miel e";
const char      *__ft_strcat_str_2__ = "t la foret!";


int     main(void) {
	bool 			success;
	const size_t	__ft_bzero_str_len__ = strlen(__ft_bzero_str__),
	                __ft_strcat_str_1_len__ = strlen(__ft_strcat_str_1__),
	                __ft_strcat_str_2_len__ = strlen(__ft_strcat_str_2__);
	char 			*__strcat__ = (char *)malloc(sizeof(char) * __ft_strcat_str_1_len__ + __ft_strcat_str_2_len__ + 1),
	     			*__ft_strcat__ = (char *)malloc(sizeof(char) * __ft_strcat_str_1_len__ + __ft_strcat_str_2_len__ + 1),
	                *__ft_bzero__ = (char *)malloc(sizeof(char) * __ft_bzero_str_len__ + 1);

#if FT_BZERO_TEST == true
	success = true;
	printf("\x1b[1;33mStarting test for ft_bzero...\x1b[0m\n");
	printf("- Buffering test string in memory...\n");
    snprintf(__ft_bzero__, __ft_bzero_str_len__ + 1, "%s", __ft_bzero_str__);
    printf(" - Passing buffered string to ft_bzero for cleanup...\n");
    ft_bzero(__ft_bzero__, __ft_bzero_str_len__);
    printf(" - Checking memory area...\n");
	for (unsigned int k = 0; k < __ft_bzero_str_len__; k++) {
		if (__ft_bzero__[k] != 0) {
			success = false;
			break;
		}
	}
    printf(" - \x1b[1;33mft_bzero, status: \x1b[0m%s\n", success ? "\x1b[32mSUCCESS\x1b[0m" : "\x1b[31mFAIL\x1b[0m");
#endif

#if FT_STRCAT_TEST == true
    printf("\n\x1b[1;33mStarting test for ft_strcat...\x1b[0m\n");
    printf(" - TEST1: User defined string\n");
    printf(" - First test string: \"%s\"\n", __ft_strcat_str_1__);
    printf(" - Second test string: \"%s\"\n", __ft_strcat_str_2__);
    printf(" - Buffering test string in memory...\n");
    snprintf(__strcat__, __ft_strcat_str_1_len__ + 1,  "%s", __ft_strcat_str_1__);
    snprintf(__ft_strcat__, __ft_strcat_str_1_len__ + 1,  "%s", __ft_strcat_str_1__);
    printf(" - Concatenating with strcat...\n");
    __strcat__ = strcat(__strcat__, __ft_strcat_str_2__);
    printf(" - Result with strcat: \"%s\"\n", __strcat__);
    printf(" - Concatenating with ft_strcat...\n");
    __ft_strcat__ = ft_strcat(__ft_strcat__, __ft_strcat_str_2__);
    printf(" - Result with ft_strcat: \"%s\"\n", __ft_strcat__);
    success = !strcmp(__strcat__, __ft_strcat__) ? true : false;
    printf(" - TEST1, status: %s\n", success ? "\x1b[32mSUCCESS\x1b[0m" : "\x1b[31mFAIL\x1b[0m");
    printf(" - TEST2: Empty string\n");
    printf(" - First test string: \"%s\"\n", __empty_string__);
    printf(" - Second test string: \"%s\"\n", __ft_strcat_str_2__);
    printf(" - Buffering test string in memory...\n");
    snprintf(__strcat__, 1,  "%s", __empty_string__);
    snprintf(__ft_strcat__, 1,  "%s", __empty_string__);
    printf(" - Concatenating with strcat...\n");
    __strcat__ = strcat(__strcat__, __ft_strcat_str_2__);
    printf(" - Result with strcat: \"%s\"\n", __strcat__);
    printf(" - Concatenating with ft_strcat...\n");
    __ft_strcat__ = ft_strcat(__ft_strcat__, __ft_strcat_str_2__);
    printf(" - Result with ft_strcat: \"%s\"\n", __ft_strcat__);
    bool success2 = !strcmp(__strcat__, __ft_strcat__) ? true : false;
    printf(" - TEST2, status: %s\n", success2 ? "\x1b[32mSUCCESS\x1b[0m" : "\x1b[31mFAIL\x1b[0m");
    printf(" - \x1b[1;33mft_strcat, status: \x1b[0m%s\n", success && success2 ? "\x1b[32mSUCCESS\x1b[0m" : "\x1b[31mFAIL\x1b[0m");
#endif

#if FT_PUTS_TEST == true
    snprintf(__ft_bzero__, __ft_bzero_str_len__ + 1, "%s", __ft_bzero_str__);
    printf("\n\x1b[1;33mStarting test for ft_puts...\x1b[0m\n");
	printf(" - Test string: \"%s\"\n - Output using puts: ", __ft_bzero__);
	int ret_value = puts(__ft_bzero__);
	printf(" - Return value with puts: %d\n", ret_value);
	dprintf(STDOUT_FILENO, " - Output using ft_puts: ");
	ret_value = ft_puts(__ft_bzero__);
    printf(" - Return value with ft_puts: %d\n", ret_value);
    printf(" - Test string: \"\"\n - Output using puts: ");
    ret_value = puts(__empty_string__);
    printf(" - Return value with puts: %d\n", ret_value);
    dprintf(STDOUT_FILENO, " - Output using ft_puts: ");
    ret_value = ft_puts(__empty_string__);
    printf(" - Return value with ft_puts: %d\n", ret_value);
    printf(" - \x1b[1;33mft_puts, status: \x1b[0m%s\n", success && success2 ? "\x1b[32mSUCCESS\x1b[0m" : "\x1b[31mFAIL\x1b[0m");
#endif

#if FT_STRLEN_TEST == true
    printf("\n\x1b[1;33mStarting test for ft_strlen...\x1b[0m\n");
    printf(" - TEST1: User defined string\n");
    printf(" - Test string: \"%s\"\n", __ft_bzero__);
    printf(" - String length using strlen: %lu\n", __ft_bzero_str_len__);
    printf(" - String length using ft_strlen: %lu\n", ft_strlen(__ft_bzero_str__));
    printf(" - TEST2: Empty string\n");
    printf(" - Test string: \"\"\n");
    printf(" - String length using strlen: %lu\n", strlen(__empty_string__));
    printf(" - String length using ft_strlen: %lu\n", ft_strlen(__empty_string__));
    printf(" - \x1b[1;33mft_strlen, status: \x1b[0m%s\n", success && success2 ? "\x1b[32mSUCCESS\x1b[0m" : "\x1b[31mFAIL\x1b[0m");
#endif
}
