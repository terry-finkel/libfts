#include "tests.h"

struct function {
	const char *name;
	int (*ptr)(int *);
};

struct function *get_next_function(void)
{
	static size_t i = 0;
	static struct function array[] = {
		{ "ft_bzero", test_bzero },
		{ "ft_strcat", test_strcat },
		{ "ft_isalpha", test_isalpha },
		{ "ft_isdigit", test_isdigit },
		{ "ft_isalnum", test_isalnum },
		{ "ft_isascii", test_isascii },
		{ "ft_isprint", test_isprint },
		{ "ft_toupper", test_toupper },
		{ "ft_tolower", test_tolower },
		{ "ft_puts", test_puts },
		{ "ft_strlen", test_strlen },
		{ "ft_memset", test_memset },
		{ "ft_memcpy", test_memcpy },
		{ "ft_strdup", test_strdup },
		{ "ft_cat", test_cat },
//		{ "ft_isblank", test_isblank },
//		{ "ft_iscntrl", test_iscntrl },
//		{ "ft_isgraph", test_isgraph },
//		{ "ft_islower", test_islower },
//		{ "ft_ispunct", test_ispunct },
//		{ "ft_isspace", test_isspace },
//		{ "ft_isupper", test_isupper },
//		{ "ft_isxdigit", test_isxdigit },
//		{ "ft_memchr", test_memchr },
		{ "ft_memcmp", test_memcmp },
//		{ "ft_strchr", test_strchr },
		{ "ft_strcmp", test_strcmp },
//		{ "ft_putchar", test_putchar }
	};

	if (i < sizeof(array) / sizeof(array[0])) {
		if (i == 0)
			printf("\e[1m--{ PART 1 }--\e[0m\n");
		if (i == 10)
			printf("\e[1m--{ PART 2 }--\e[0m\n");
		if (i == 14)
			printf("\e[1m--{ PART 3 }--\e[0m\n");
		if (i == 15)
			printf("\e[1m--{ BONUSES }--\e[0m\n");
		return (array + i++);
	}
	return (NULL);
}

int main(void)
{
	struct function *f;
	int failure = 0;

	while ((f = get_next_function())) {
		printf("\e[1m- %s:\e[0m ", f->name);
		int nb, fail;
		fail = f->ptr(&nb);
		if (fail) {
			printf("\n\e[31m[%d ko]\e[0m (%d tests)\n", fail, nb);
			failure++;
		} else {
			printf("\t\e[32m[OK]\e[0m (%d tests)\n", nb);
		}
	}
	if (failure) {
		printf("\e[31;1m>>> %d failed function%c <<<\e[0m\n", failure,
		       (failure > 1 ? 's' : 0));
	} else {
		printf("\e[32;1m>>> All tests passed! <<<\n\e[0m");
	}
	return (failure);
}
