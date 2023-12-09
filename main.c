/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/08 23:55:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf_bonus.h"
//#define ARGS "==%d%s%c%i%%%u%x==\n", -200, "HELLO", '?', 19, -1, 1025
//#define ARGS "==%s==\n", "HELLO"
//#define ARGS "==%d==\n", -200
//#define ARGS "==%i==\n", 12345
//#define ARGS "==%u==\n", 0
//#define ARGS "==%%==\n"
//#define ARGS "==%c==\n", '?'
//#define ARGS "==%x==\n", 253
//#define ARGS "==%X==\n", 1244
//#define ARGS "==%p==\n", (void *) LONG_MIN
//#define ARGS "==%010c==\n", 'x'
//#define ARGS " %-11p %-12p ", INT_MIN, INT_MAX
//#define ARGS "==%10p==", &ret
//#define ARGS "==%10p==", (void *) 1300874
//#define ARGS "==%-10p==", (void *) 1399990
//#define ARGS "==%20.10p==", (void *) 1399990
//define ARGS "==%10.1p==", (void *) 1399990
//#define ARGS "==%10p==", (void *) 0
//#define ARGS "==%-10p==", (void *) 0
//#define ARGS "==%p==", (void *) 0
//#define ARGS "==%2p==", (void *) -1
//#define ARGS "==%-2p==", (void *) -1
//#define ARGS "==%-9p==", (void *) LONG_MIN
//#define ARGS "==%-9p==", (void *) LONG_MAX
//#define ARGS "==%-9p==", (void *) &ret
//#define ARGS "==%-9%=="
#define ARGS "==%19%=="

//52: 	TEST(26, print(" %-9p %-10p ", LONG_MIN, LONG_MAX));
//53: 	TEST(27, print(" %-11p %-12p ", INT_MIN, INT_MAX));
//55: 	TEST(29, print(" %-1p %-2p ", 0, 0));


int	main(void)
{
	int	ret;

	printf("\nprintf:\n");
	ret = printf(ARGS);
	printf("\nret %i\n", ret);
	printf("\nft_printf:\n");
	ret = ft_printf(ARGS);
	printf("\nret %i\n", ret);
	return (0);
}
