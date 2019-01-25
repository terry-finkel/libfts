#include "libfts.h"
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define FT_BZERO_TEST   true
#define FT_STRCAT_TEST  true
#define FT_ISALPHA_TEST true
#define FT_ISDIGIT_TEST true
#define FT_ISALNUM_TEST true
#define FT_ISASCII_TEST true
#define FT_ISPRINT_TEST true
#define FT_PUTS_TEST    true
#define FT_STRLEN_TEST  true
#define FT_TOUPPER_TEST true
#define FT_TOLOWER_TEST true
#define FT_MEMSET_TEST  true
#define FT_MEMCPY_TEST  true
#define FT_STRDUP_TEST  true


const char      *__empty_string__ = "";
const char 		*__ft_bzero_str__ = "Le caca c'est bien mais le miel c'est quand meme beaucoup mieux...";
const char      *__ft_memcpy_dest__ = "Repeats a string instruction the number of times specified in the count register";
const char      *__ft_memcpy_src__ = "((E)CX)";
const char      __ft_memset_char__ = 'Z';
const char      *__ft_memset_str__ = "Salut je fais de l'assembleur et je suis trop fort!";
const char      *__ft_strcat_str_1__ = "Le miel e";
const char      *__ft_strcat_str_2__ = "t la foret!";
const char      *__ft_strdup_str__ = "This string is going to be duplicated, hurray!";
const char      *__ft_strlen_str__ = "TROP LONG LE STRING DE OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOUUUUUUUUUUUFFFFFFFFFFFFFF";


int     main(void) {
    int 			success, success2, ret_value, ft_ret_value;
    size_t          st_ret_value, ft_st_ret_value;
    const size_t	__ft_bzero_str_len__ = strlen(__ft_bzero_str__),
                    __ft_memcpy_dest_len__ = strlen(__ft_memcpy_dest__),
                    __ft_memcpy_src_len__ = strlen(__ft_memcpy_src__),
	                __ft_memset_str_len__ = strlen(__ft_memset_str__),
	                __ft_strcat_str_1_len__ = strlen(__ft_strcat_str_1__),
	                __ft_strcat_str_2_len__ = strlen(__ft_strcat_str_2__);
	char 		    *__bzero__ = (char *)malloc(sizeof(char) * __ft_bzero_str_len__ + 1),
	                *__ft_bzero__ = (char *)malloc(sizeof(char) * __ft_bzero_str_len__ + 1),
	                *__memcpy__ = (char *)malloc(sizeof(char) * __ft_memcpy_dest_len__ + 1),
	                *__ft_memcpy__ = (char *)malloc(sizeof(char) * __ft_memcpy_dest_len__ + 1),
	                *__ft_memset__ = (char *)malloc(sizeof(char) * __ft_memset_str_len__ + 1),
	                *__memset__ = (char *)malloc(sizeof(char) * __ft_memset_str_len__ + 1),
	     			*__ft_strcat__ = (char *)malloc(sizeof(char) * __ft_strcat_str_1_len__ + __ft_strcat_str_2_len__ + 1),
                    *__strcat__ = (char *)malloc(sizeof(char) * __ft_strcat_str_1_len__ + __ft_strcat_str_2_len__ + 1);

#if FT_BZERO_TEST == true
# define TEST_STR "ft_bzero"
    printf("\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
	printf(" - Buffering test strings in memory...\n");
    snprintf(__bzero__, __ft_bzero_str_len__ + 1, "%s", __ft_bzero_str__);
    snprintf(__ft_bzero__, __ft_bzero_str_len__ + 1, "%s", __ft_bzero_str__);
    printf(" - Passing first buffered string to bzero for cleanup...\n");
    bzero(__bzero__, __ft_bzero_str_len__);
    printf(" - Passing second buffered string to ft_bzero for cleanup...\n");
    ft_bzero(__ft_bzero__, __ft_bzero_str_len__);
    printf(" - Checking memory area...\n");
	success = !memcmp(__ft_bzero__, __bzero__, __ft_bzero_str_len__) ? 1 : 0;
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#if FT_STRCAT_TEST == true
# define TEST_STR "ft_strcat"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - \x1b[1;33mTEST1: User defined string\x1b[0m\n");
    printf(" - First test string: \"%s\"\n", __ft_strcat_str_1__);
    printf(" - Second test string: \"%s\"\n", __ft_strcat_str_2__);
    printf(" - Buffering test strings in memory...\n");
    snprintf(__strcat__, __ft_strcat_str_1_len__ + 1,  "%s", __ft_strcat_str_1__);
    snprintf(__ft_strcat__, __ft_strcat_str_1_len__ + 1,  "%s", __ft_strcat_str_1__);
    printf(" - Concatenating with strcat...\n");
    __strcat__ = strcat(__strcat__, __ft_strcat_str_2__);
    printf(" - Result with strcat: \"%s\"\n", __strcat__);
    printf(" - Concatenating with ft_strcat...\n");
    __ft_strcat__ = ft_strcat(__ft_strcat__, __ft_strcat_str_2__);
    printf(" - Result with ft_strcat: \"%s\"\n", __ft_strcat__);
    success = !strcmp(__strcat__, __ft_strcat__) ? 1 : 0;
    printf(" - \x1b[1;33mTEST1: \x1b[0m%s\x1b[0m\n", success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33mTEST2: Empty string\x1b[0m\n");
    printf(" - First test string: \"%s\"\n", __empty_string__);
    printf(" - Second test string: \"%s\"\n", __ft_strcat_str_2__);
    printf(" - Buffering test strings in memory...\n");
    snprintf(__strcat__, 1,  "%s", __empty_string__);
    snprintf(__ft_strcat__, 1,  "%s", __empty_string__);
    printf(" - Concatenating with strcat...\n");
    __strcat__ = strcat(__strcat__, __ft_strcat_str_2__);
    printf(" - Result with strcat: \"%s\"\n", __strcat__);
    printf(" - Concatenating with ft_strcat...\n");
    __ft_strcat__ = ft_strcat(__ft_strcat__, __ft_strcat_str_2__);
    printf(" - Result with ft_strcat: \"%s\"\n", __ft_strcat__);
    success2 = !strcmp(__strcat__, __ft_strcat__) ? 1 : 0;
    printf(" - \x1b[1;33mTEST2: \x1b[0m%s\x1b[0m\n", success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#if FT_ISALPHA_TEST == true
# define TEST_STR "ft_isalpha"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_isalpha(c) != isalpha(c)) {
            success = 0;
            break;
        }
    }
    if (ft_isalpha(UCHAR_MAX) != isalpha(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_ISDIGIT_TEST == true
# define TEST_STR "ft_isdigit"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_isdigit(c) != isdigit(c)) {
            success = 0;
            break;
        }
    }
    if (ft_isdigit(UCHAR_MAX) != isdigit(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_ISALNUM_TEST == true
# define TEST_STR "ft_isalnum"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_isalnum(c) != isalnum(c)) {
            success = 0;
            break;
        }
    }
    if (ft_isalnum(UCHAR_MAX) != isalnum(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_ISASCII_TEST == true
# define TEST_STR "ft_isascii"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_isascii(c) != isascii(c)) {
            success = 0;
            break;
        }
    }
    if (ft_isascii(UCHAR_MAX) != isascii(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_ISPRINT_TEST == true
# define TEST_STR "ft_isprint"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_isprint(c) != isprint(c)) {
            success = 0;
            break;
        }
    }
    if (ft_isprint(UCHAR_MAX) != isprint(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_TOUPPER_TEST == true
# define TEST_STR "ft_toupper"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_toupper(c) != toupper(c)) {
            success = 0;
            break;
        }
    }
    if (ft_toupper(UCHAR_MAX) != toupper(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_TOLOWER_TEST == true
# define TEST_STR "ft_tolower"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    for (unsigned char c = 0; c < UCHAR_MAX; c++) {
        if (ft_tolower(c) != tolower(c)) {
            success = 0;
            break;
        }
    }
    if (ft_tolower(UCHAR_MAX) != tolower(UCHAR_MAX)) success = 0;
    printf(" - \x1b[1;33m%s, status: \x1b[0m\x1b[32m%s\x1b[0m\n", TEST_STR, success ? "SUCCESS" : "FAIL");
# undef TEST_STR
#endif

#if FT_PUTS_TEST == true
# define TEST_STR "ft_puts"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    snprintf(__ft_bzero__, __ft_bzero_str_len__ + 1, "%s", __ft_bzero_str__);
    printf(" - \x1b[1;33mTEST1: User defined string\x1b[0m\n");
    printf(" - Test string: \"%s\"\n - Output using puts: ", __ft_bzero__);
	ret_value = puts(__ft_bzero__);
	printf(" - Return value with puts: %d\n", ret_value);
	dprintf(STDOUT_FILENO, " - Output using ft_puts: ");
	ft_ret_value = ft_puts(__ft_bzero__);
    printf(" - Return value with ft_puts: %d\n", ft_ret_value);
    success = ret_value == ft_ret_value ? 1 : 0;
    printf(" - \x1b[1;33mTEST1: \x1b[0m%s\x1b[0m\n", success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33mTEST2: Empty string\x1b[0m\n");
    printf(" - Test string: \"\"\n - Output using puts: ");
    ret_value = puts(__empty_string__);
    printf(" - Return value with puts: %d\n", ret_value);
    dprintf(STDOUT_FILENO, " - Output using ft_puts: ");
    ft_ret_value = ft_puts(__empty_string__);
    printf(" - Return value with ft_puts: %d\n", ft_ret_value);
    success2 = ret_value == ft_ret_value ? 1 : 0;
    printf(" - \x1b[1;33mTEST2: \x1b[0m%s\x1b[0m\n", success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#if FT_STRLEN_TEST == true
# define TEST_STR "ft_strlen"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - \x1b[1;33mTEST1: User defined string\x1b[0m\n");
    printf(" - Test string: \"%s\"\n", __ft_strlen_str__);
    st_ret_value = strlen(__ft_strlen_str__);
    printf(" - String length using strlen: %lu\n", st_ret_value);
    ft_st_ret_value = ft_strlen(__ft_strlen_str__);
    printf(" - String length using ft_strlen: %lu\n", ft_st_ret_value);
    success = st_ret_value == ft_st_ret_value ? 1 : 0;
    printf(" - \x1b[1;33mTEST1: \x1b[0m%s\x1b[0m\n", success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33mTEST2: Empty string\x1b[0m\n");
    printf(" - Test string: \"\"\n");
    st_ret_value = strlen(__empty_string__);
    printf(" - String length using strlen: %lu\n", st_ret_value);
    ft_st_ret_value = ft_strlen(__empty_string__);
    printf(" - String length using ft_strlen: %lu\n", ft_st_ret_value);
    success = st_ret_value == ft_st_ret_value ? 1 : 0;
    printf(" - \x1b[1;33mTEST2: \x1b[0m%s\x1b[0m\n", success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#if FT_MEMSET_TEST == true
# define TEST_STR "ft_memset"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf("- Buffering test strings in memory...\n");
    snprintf(__memset__, __ft_memset_str_len__ + 1, "%s", __ft_memset_str__);
    snprintf(__ft_memset__, __ft_memset_str_len__ + 1, "%s", __ft_memset_str__);
    printf(" - \x1b[1;33mTEST1: Set to \'%c\'\x1b[0m\n", __ft_memset_char__);
    printf(" - Passing first buffered string to memset...\n");
    memset(__memset__, __ft_memset_char__, __ft_memset_str_len__);
    printf(" - Result: \"%s\"\n", __memset__);
    printf(" - Passing second buffered string to ft_memset...\n");
    ft_memset(__ft_memset__, __ft_memset_char__, __ft_memset_str_len__);
    printf(" - Result: \"%s\"\n", __ft_memset__);
    printf(" - Comparing memory area...\n");
    success = !memcmp(__memset__, __ft_memset__, __ft_memset_str_len__) ? 1 : 0;
    printf(" - \x1b[1;33mTEST1: \x1b[0m%s\x1b[0m\n", success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33mTEST2: Clean memory area\x1b[0m\n");
    printf(" - Passing first buffered string to memset for cleanup...\n");
    memset(__memset__, 0, __ft_memset_str_len__);
    printf(" - Passing second buffered string to ft_memset for cleanup...\n");
    ft_memset(__ft_memset__, 0, __ft_memset_str_len__);
    printf(" - Checking memory area...\n");
    success2 = !memcmp(__memset__, __ft_memset__, __ft_memset_str_len__) ? 1 : 0;
    printf(" - \x1b[1;33mTEST2: \x1b[0m%s\x1b[0m\n", success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#if FT_MEMCPY_TEST == true
# define TEST_STR "ft_memcpy"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - Buffering test strings in memory...\n");
    snprintf(__memcpy__, __ft_memcpy_dest_len__ + 1, "%s", __ft_memcpy_dest__);
    snprintf(__ft_memcpy__, __ft_memcpy_dest_len__ + 1, "%s", __ft_memcpy_dest__);
    printf(" - Destination memory area reads: \"%s\"\n", __ft_memcpy_dest__);
    printf(" - Source memory area reads: \"%s\"\n", __ft_memcpy_src__);
    printf(" - Copying using memcpy...\n");
    memcpy(__memcpy__, __ft_memcpy_src__, __ft_memcpy_src_len__);
    printf(" - Output using memcpy: \"%s\"\n", __memcpy__);
    printf(" - Copying using ft_memcpy...\n");
    ft_memcpy(__ft_memcpy__, __ft_memcpy_src__, __ft_memcpy_src_len__);
    printf(" - Output using ft_memcpy: \"%s\"\n", __ft_memcpy__);
    printf(" - Comparing memory area...\n");
    success = !memcmp(__memcpy__, __ft_memcpy__, __ft_memcpy_src_len__) ? 1 : 0;
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#if FT_STRDUP_TEST == true
# define TEST_STR "ft_strdup"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - Duping string with strdup...\n");
    const char *__strdup__ = strdup(__ft_strdup_str__);
    printf(" - Duping string with ft_strdup...\n");
    const char *__ft_strdup__ = ft_strdup(__ft_strdup_str__);
    printf(" - Comparing strings...\n");
    success = !strcmp(__strdup__, __ft_strdup__) ? 1 : 0;
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

    return EXIT_SUCCESS;
}
