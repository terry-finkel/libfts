#include "include/libfts.h"
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define FT_BZERO_TEST
#define FT_STRCAT_TEST
#define FT_ISALPHA_TEST
#define FT_ISDIGIT_TEST
#define FT_ISALNUM_TEST
#define FT_ISASCII_TEST
#define FT_ISPRINT_TEST
#define FT_PUTS_TEST
#define FT_STRLEN_TEST
#define FT_TOUPPER_TEST
#define FT_TOLOWER_TEST
#define FT_MEMSET_TEST
#define FT_MEMCPY_TEST
#define FT_STRDUP_TEST
#define FT_CAT_TEST
#define FT_ABS_TEST
#define FT_ITOA_TEST
#define FT_MEMCMP_TEST
#define FT_MEMMOVE_TEST
#define FT_STRCMP_TEST

# ifndef ABS
#  define ABS(x) ({__typeof__(x) _x = (x);_x < 0 ? -_x : _x;})
# endif

#ifndef MIN
# define MIN(a, b) ({__typeof__(a)_a=(a);__typeof__(b)_b=(b);_a>_b ? _b : _a;})
#endif


const char      *__empty_string__ = "",
                *__ft_bzero_str__ = "Le miel c'est bien mais la foret c'est quand meme beaucoup mieux...",
                *__ft_memcmp_str_1__ = "and x, y\ty ← x and y",
                *__ft_memcmp_str_2__ = "and x, y\tx ← x and b",
                *__ft_memcmp_str_3__ = "and x, y\tx ← x and y",
                *__ft_memcpy_dest__ = "Repeats a string instruction the number of times specified in the count register",
                *__ft_memcpy_src__ = "((E)CX)",
                *__ft_memmove_str__ = "Convert Word to Doubleword/Convert Doubleword to Quadword",
                *__ft_memset_str__ = "Salut je fais de l'assembleur et je suis trop fort!",
                *__ft_strcat_str_1__ = "Le miel e",
                *__ft_strcat_str_2__ = "t la foret!",
                *__ft_strcmp_str__ = "We won’t get too fancy",
                *__ft_strcmp_str_2__ = "We won’t get too fancy",
                *__ft_strdup_str__ = "This string is going to be duplicated, hurray!",
                *__ft_strlen_str__ = "TROP LONG LE STRING DE OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOUUUUUUUUUUUFFFFFFFFFFFFFF";
const char      __ft_memset_char__ = 'Z';
const int       num_1 = 42, num_2 = -101010, num_3 = 0, num_4 = INT_MAX, num_5 = INT_MIN, MEMMOVE_OFFSET = 3;


int     main(void) {
    int 			success, success2, success3, success4, success5, ret_value, ft_ret_value;
    size_t          st_ret_value, ft_st_ret_value;
    const size_t	__ft_bzero_str_len__ = strlen(__ft_bzero_str__),
                    __ft_memcmp_len_1__ = MIN(strlen(__ft_memcmp_str_1__), strlen(__ft_memcmp_str_2__)),
                    __ft_memcmp_len_2__ = MIN(strlen(__ft_memcmp_str_2__), strlen(__ft_memcmp_str_3__)),
                    __ft_memcmp_len_3__ = MIN(strlen(__ft_memcmp_str_3__), strlen(__ft_memcmp_str_1__)),
                    __ft_memcpy_dest_len__ = strlen(__ft_memcpy_dest__),
                    __ft_memcpy_src_len__ = strlen(__ft_memcpy_src__),
                    __ft_memmove_str_len__ = strlen(__ft_memmove_str__),
	                __ft_memset_str_len__ = strlen(__ft_memset_str__),
	                __ft_strcat_str_1_len__ = strlen(__ft_strcat_str_1__),
	                __ft_strcat_str_2_len__ = strlen(__ft_strcat_str_2__);
    char 		    *__bzero__ = (char *)malloc(sizeof(char) * __ft_bzero_str_len__ + 1),
	                *__ft_bzero__ = (char *)malloc(sizeof(char) * __ft_bzero_str_len__ + 1),
	                *__memcpy__ = (char *)malloc(sizeof(char) * __ft_memcpy_dest_len__ + 1),
	                *__ft_memcpy__ = (char *)malloc(sizeof(char) * __ft_memcpy_dest_len__ + 1),
	                *__memmove_src__ = (char *)malloc(sizeof(char) * __ft_memmove_str_len__ + 1),
	                *__ft_memmove_src__ = (char *)malloc(sizeof(char) * __ft_memmove_str_len__ + 1),
	                *__ft_memset__ = (char *)malloc(sizeof(char) * __ft_memset_str_len__ + 1),
	                *__memset__ = (char *)malloc(sizeof(char) * __ft_memset_str_len__ + 1),
	     			*__ft_strcat__ = (char *)malloc(sizeof(char) * __ft_strcat_str_1_len__ + __ft_strcat_str_2_len__ + 1),
                    *__strcat__ = (char *)malloc(sizeof(char) * __ft_strcat_str_1_len__ + __ft_strcat_str_2_len__ + 1);
    void            *__ft_memmove_dest__ = __ft_memmove_src__ + MEMMOVE_OFFSET,
                    *__memmove_dest__ = __memmove_src__ + MEMMOVE_OFFSET;

    printf("\x1b[32m-----------------------------------\n");
	printf("       MANDATORY PART TESTS\n");
    printf("-----------------------------------\x1b[0m\n");

#ifdef FT_BZERO_TEST
# define TEST_STR "ft_bzero"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
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

#ifdef FT_STRCAT_TEST
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

#ifdef FT_ISALPHA_TEST
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

#ifdef FT_ISDIGIT_TEST
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

#ifdef FT_ISALNUM_TEST
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

#ifdef FT_ISASCII_TEST
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

#ifdef FT_ISPRINT_TEST
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

#ifdef FT_TOUPPER_TEST
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

#ifdef FT_TOLOWER_TEST
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

#ifdef FT_PUTS_TEST
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

#ifdef FT_STRLEN_TEST
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

#ifdef FT_MEMSET_TEST
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

#ifdef FT_MEMCPY_TEST
# define TEST_STR "ft_memcpy"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - Buffering test strings in memory...\n");
    snprintf(__memcpy__, __ft_memcpy_dest_len__ + 1, "%s", __ft_memcpy_dest__);
    snprintf(__ft_memcpy__, __ft_memcpy_dest_len__ + 1, "%s", __ft_memcpy_dest__);
    printf(" - Destination memory area reads: \"%s\"\n", __ft_memcpy_dest__);
    printf(" - Source memory area reads: \"%s\"\n", __ft_memcpy_src__);
    printf(" - \x1b[1;33mTEST1: Copy non-null string\x1b[0m\n");
    printf(" - Copying using memcpy...\n");
    memcpy(__memcpy__, __ft_memcpy_src__, __ft_memcpy_src_len__);
    printf(" - Output using memcpy: \"%s\"\n", __memcpy__);
    printf(" - Copying using ft_memcpy...\n");
    ft_memcpy(__ft_memcpy__, __ft_memcpy_src__, __ft_memcpy_src_len__);
    printf(" - Output using ft_memcpy: \"%s\"\n", __ft_memcpy__);
    printf(" - Comparing memory area...\n");
    success = !memcmp(__memcpy__, __ft_memcpy__, __ft_memcpy_src_len__) ? 1 : 0;
    printf(" - \x1b[1;33mTEST1: \x1b[0m%s\x1b[0m\n", success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33mTEST2: Copy 0 characters\x1b[0m\n");
    printf(" - Buffering test strings in memory...\n");
    snprintf(__memcpy__, __ft_memcpy_dest_len__ + 1, "%s", __ft_memcpy_dest__);
    snprintf(__ft_memcpy__, __ft_memcpy_dest_len__ + 1, "%s", __ft_memcpy_dest__);
    printf(" - Copying using memcpy...\n");
    memcpy(__memcpy__, __ft_memcpy_src__, 0);
    printf(" - Output using memcpy: \"%s\"\n", __memcpy__);
    printf(" - Copying using ft_memcpy...\n");
    ft_memcpy(__ft_memcpy__, __ft_memcpy_src__, 0);
    printf(" - Output using ft_memcpy: \"%s\"\n", __ft_memcpy__);
    printf(" - Comparing memory area...\n");
    success2 = !memcmp(__memcpy__, __ft_memcpy__, __ft_memcpy_src_len__) ? 1 : 0;
    printf(" - \x1b[1;33mTEST2: \x1b[0m%s\x1b[0m\n", success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#ifdef FT_STRDUP_TEST
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

#ifdef FT_CAT_TEST
# define TEST_STR "ft_cat"
    success = 1;
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - Please enter path to file you want to display:\n - File name: ");

    //Get file path from user
    char buffer[4096];
    memset(buffer, 0, 4096);
    (void)(scanf("%s", buffer) + 1);
    const int fd = open(buffer, O_RDONLY);
    if (fd == -1) {
        printf(" - File was not found, aborting %s test...\n", TEST_STR);
        goto FT_CAT_TEST_END;
    }

    //Save STDOUT before redirection
    dup2(1, 1010);

    //Output cat into cat.test
    pid_t id = fork();
    if (id == 0) {
        char *const argv[] = {"cat", buffer, NULL};
        int output_fd = open("cat.test", O_WRONLY | O_CREAT | O_TRUNC, 0744);
        dup2(output_fd, 1);
        execve("/bin/cat", argv, NULL);
        close(output_fd);
    }
    wait(&id);

    //Uses ft_cat on file and output result in ft_cat.test
    int output_fd = open("ft_cat.test", O_WRONLY | O_CREAT | O_TRUNC, 0744);
    dup2(output_fd, 1);
    ft_cat(fd);
    close(output_fd);

    //Read output in both files
    int cat_fd = open("cat.test", O_RDONLY);
    int ft_cat_fd = open("ft_cat.test", O_RDONLY);
    char ft_buffer[4096];
    memset(ft_buffer, 0, 4096);
    ssize_t bytes;
    while ((bytes = read(cat_fd, &buffer, 4096))) {
        if (bytes == -1) return EXIT_FAILURE;

        (void)(read(ft_cat_fd, &ft_buffer, (size_t)bytes) + 1);
        if (strncmp(buffer, ft_buffer, (size_t)bytes) != 0) {
            success = 0;
            break;
        }
    }

    //Restore STDOUT
    dup2(1010, 1);

    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    FT_CAT_TEST_END: ;
# undef TEST_STR
#endif

    printf("\n\x1b[32m-----------------------------------\n");
    printf("         BONUS PART TESTS\n");
    printf("-----------------------------------\x1b[0m\n");

#ifdef FT_ABS_TEST
# define TEST_STR "ft_abs"
    printf("\n\x1b[1;33mStarting tests for %s...\x1b[0m\n", TEST_STR);
    success = ft_abs(num_1) == ABS(num_1) ? 1 : 0;
    success2 = ft_abs(num_2) == ABS(num_2) ? 1 : 0;
    success3 = ft_abs(num_3) == ABS(num_3) ? 1 : 0;
    success4 = ft_abs(num_4) == ABS(num_4) ? 1 : 0;
    success5 = ft_abs(num_5 + 1) == ABS(num_5 + 1) ? 1 : 0;
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 && success3 && success4 && success5 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#ifdef FT_ITOA_TEST
# define TEST_STR "ft_itoa"
    printf("\n\x1b[1;33mStarting tests for %s...\x1b[0m\n", TEST_STR);
    char itoa_ret[32];
    sprintf(itoa_ret, "%d", num_1);
    char *ft_itoa_ret = ft_itoa(num_1);
    success = !strcmp(itoa_ret, ft_itoa_ret);
    free(ft_itoa_ret);
    sprintf(itoa_ret, "%d", num_2);
    ft_itoa_ret = ft_itoa(num_2);
    success2 = !strcmp(itoa_ret, ft_itoa_ret);
    free(ft_itoa_ret);
    sprintf(itoa_ret, "%d", num_3);
    ft_itoa_ret = ft_itoa(num_3);
    success3 = !strcmp(itoa_ret, ft_itoa_ret);
    free(ft_itoa_ret);
    sprintf(itoa_ret, "%d", num_4);
    ft_itoa_ret = ft_itoa(num_4);
    success4 = !strcmp(itoa_ret, ft_itoa_ret);
    free(ft_itoa_ret);
    sprintf(itoa_ret, "%d", num_5);
    ft_itoa_ret = ft_itoa(num_5);
    success5 = !strcmp(itoa_ret, ft_itoa_ret);
    free(ft_itoa_ret);
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 && success3 && success4 && success5 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#ifdef FT_MEMCMP_TEST
# define TEST_STR "ft_memcmp"
    printf("\n\x1b[1;33mStarting tests for %s...\x1b[0m\n", TEST_STR);
    success = memcmp(__ft_memcmp_str_1__, __ft_memcmp_str_2__, __ft_memcmp_len_1__)
              == ft_memcmp(__ft_memcmp_str_1__, __ft_memcmp_str_2__, __ft_memcmp_len_1__) ? 1 : 0;
    success2 = memcmp(__ft_memcmp_str_2__, __ft_memcmp_str_3__, __ft_memcmp_len_2__)
               == ft_memcmp(__ft_memcmp_str_2__, __ft_memcmp_str_3__, __ft_memcmp_len_2__) ? 1 : 0;
    success3 = memcmp(__ft_memcmp_str_3__, __ft_memcmp_str_1__, __ft_memcmp_len_3__)
               == ft_memcmp(__ft_memcmp_str_3__, __ft_memcmp_str_1__, __ft_memcmp_len_3__) ? 1 : 0;
    success4 = memcmp(__ft_memcmp_str_1__, __ft_memcmp_str_1__, __ft_memcmp_len_1__)
                   == ft_memcmp(__ft_memcmp_str_1__, __ft_memcmp_str_1__, __ft_memcmp_len_1__) ? 1 : 0;
    success5 = memcmp(__ft_memcmp_str_1__, __ft_memcmp_str_1__, 0)
                   == ft_memcmp(__ft_memcmp_str_1__, __ft_memcmp_str_1__, 0) ? 1 : 0;
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 && success3 && success4 && success5 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#ifdef FT_MEMMOVE_TEST
# define TEST_STR "ft_memmove"
    printf("\n\x1b[1;33mStarting test for %s...\x1b[0m\n", TEST_STR);
    printf(" - Buffering test strings in memory...\n");
    snprintf(__memmove_src__, __ft_memmove_str_len__ + 1, "%s", __ft_memmove_str__);
    snprintf(__ft_memmove_src__, __ft_memmove_str_len__ + 1, "%s", __ft_memmove_str__);
    printf(" - Destination memory area reads: \"%s\"\n", (char *)__memmove_dest__);
    printf(" - Source memory area reads: \"%s\"\n", __memmove_src__);
    printf(" - \x1b[1;33mTEST1: Copy non-null string\x1b[0m\n");
    printf(" - Copying using memmove...\n");
    memmove(__memmove_dest__, __memmove_src__, __ft_memmove_str_len__ - MEMMOVE_OFFSET);
    printf(" - Output using memmove: \"%s\"\n", (char *)__memmove_dest__);
    printf(" - Copying using ft_memmove...\n");
    ft_memmove(__ft_memmove_dest__, __ft_memmove_src__, __ft_memmove_str_len__ - MEMMOVE_OFFSET);
    printf(" - Output using ft_memmove: \"%s\"\n", (char *)__ft_memmove_dest__);
    printf(" - Comparing memory area...\n");
    success = !memcmp(__memmove_dest__, __ft_memmove_dest__, __ft_memmove_str_len__ - MEMMOVE_OFFSET) ? 1 : 0;
    printf(" - \x1b[1;33mTEST1: \x1b[0m%s\x1b[0m\n", success ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33mTEST2: Copy 0 characters\x1b[0m\n");
    printf(" - Buffering test strings in memory...\n");
    snprintf(__memmove_src__, __ft_memmove_str_len__ + 1, "%s", __ft_memmove_str__);
    snprintf(__ft_memmove_src__, __ft_memmove_str_len__ + 1, "%s", __ft_memmove_str__);
    printf(" - Copying using memmove...\n");
    memmove(__memmove_dest__, __memmove_src__, 0);
    printf(" - Output using memmove: \"%s\"\n", (char *)__memmove_dest__);
    printf(" - Copying using ft_memmove...\n");
    ft_memmove(__ft_memmove_dest__, __ft_memmove_src__, 0);
    printf(" - Output using ft_memmove: \"%s\"\n", (char *)__ft_memmove_dest__);
    printf(" - Comparing memory area...\n");
    success2 = !memcmp(__memmove_dest__, __ft_memmove_dest__, __ft_memmove_str_len__ - MEMMOVE_OFFSET) ? 1 : 0;
    printf(" - \x1b[1;33mTEST2: \x1b[0m%s\x1b[0m\n", success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

#ifdef FT_STRCMP_TEST
# define TEST_STR "ft_strcmp"
    printf("\n\x1b[1;33mStarting tests for %s...\x1b[0m\n", TEST_STR);
    success = strcmp(__ft_strcmp_str__, __ft_strcmp_str_2__) == ft_strcmp(__ft_strcmp_str__, __ft_strcmp_str_2__) ? 1 : 0;
    success2 = strcmp(__ft_strcmp_str__, __ft_strdup_str__) == ft_strcmp(__ft_strcmp_str__, __ft_strdup_str__) ? 1 : 0;
    success3 = strcmp(__ft_memcpy_src__, __ft_memcpy_dest__) == ft_strcmp(__ft_memcpy_src__, __ft_memcpy_dest__) ? 1 : 0;
    printf(" - \x1b[1;33m%s, result: \x1b[0m%s\x1b[0m\n", TEST_STR, success && success2 && success3 ? "\x1b[32mSUCCESS" : "\x1b[1;34mFAIL");
# undef TEST_STR
#endif

    return EXIT_SUCCESS;
}
