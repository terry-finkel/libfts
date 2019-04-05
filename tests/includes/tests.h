/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:49:00 by pguillie          #+#    #+#             */
/*   Updated: 2019/03/02 18:47:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>

# include "libfts.h"

/*
 * Mandatory
 */

/* part 1 */

int test_bzero(int *nb);
int test_strcat(int *nb);
int test_isalpha(int *nb);
int test_isdigit(int *nb);
int test_isalnum(int *nb);
int test_isascii(int *nb);
int test_isprint(int *nb);
int test_toupper(int *nb);
int test_tolower(int *nb);
int test_puts(int *nb);

/* part 2 */

int test_strlen(int *nb);
int test_memset(int *nb);
int test_memcpy(int *nb);
int test_strdup(int *nb);

/* part 3  */

int test_cat(int *nb);

/*
 * Bonus
 */

int test_isblank(int *nb);
int test_iscntrl(int *nb);
int test_isgraph(int *nb);
int test_islower(int *nb);
int test_ispunct(int *nb);
int test_isspace(int *nb);
int test_isupper(int *nb);
int test_isxdigit(int *nb);
int test_memchr(int *nb);
int test_memcmp(int *nb);
int test_strchr(int *nb);
int test_strcmp(int *nb);
int test_putchar(int *nb);

/*
 * Private
 */

# define CTYPE_TEST_MIN -1024
# define CTYPE_TEST_MAX 2048

# define CAT_OUT "ft_cat_out"
# define CAT_DIF "ft_cat_dif"

int test_ctype(int (*real)(int), int (*mine)(int), int *nb);

#endif /* TESTS_H */
