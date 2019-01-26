#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

void        ft_bzero(void *s, size_t n);
void        ft_cat(const int fd);
int         ft_isalnum(int c);
int         ft_isalpha(int c);
int         ft_isascii(int c);
int         ft_isdigit(int c);
int         ft_isprint(int c);
void        *ft_memcpy(void *dest, const void *src, size_t n);
void        *ft_memset(void *s, int c, size_t n);
int         ft_puts(const char *s);
char        *ft_strcat(char *dest, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
char        *ft_strdup(const char *s);
size_t      ft_strlen(const char *s);
int         ft_tolower(int c);
int         ft_toupper(int c);

#endif