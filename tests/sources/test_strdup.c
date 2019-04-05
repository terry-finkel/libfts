/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:41:18 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/22 18:51:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int unit_test(const char *str)
{
	char *dup = ft_strdup(str);
	if (dup == NULL) {
		printf("\nWARNING: strdup returned (null)");
		return (0);
	}
	return (!strcmp(str, dup));
}

int test_strdup(int *nb)
{
	static char *str[] = {
		"", "hello world!", "foobarbaz", "012345679", "-42",
		"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
	};
	int failed = 0;

	*nb = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < *nb; i++) {
		if (unit_test(str[i]) == 0) {
			printf("\nfailed test %d: \"%s\"", i, str[i]);
			failed++;
		}
	}
	return (failed);
}
