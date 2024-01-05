/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/05 20:18:01 by maurodri         ###   ########.fr       */
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
//#define ARGS "==%10.1p==", (void *) 1399990
//#define ARGS "==%10p==", (void *) 0
//#define ARGS "==%-10p==", (void *) 0
//#define ARGS "==%p==", (void *) 0
//#define ARGS "==%2p==", (void *) -1
//#define ARGS "==%-2p==", (void *) -1
//#define ARGS "==%-9p==", (void *) LONG_MIN
//#define ARGS "==%-9p==", (void *) LONG_MAX
//#define ARGS "==%-9p==", (void *) &ret
//#define ARGS "==% -10p==", (void *) 255
//#define ARGS "==%-.9%=="
//#define ARGS "==%5%=="
//#define ARGS "==%-5%=="
//#define ARGS "==%-05%=="
//#define ARGS "==%10.u==", 0
//#define ARGS "==%10.0u==", 0
//#define ARGS "==%-.u==", 0
//#define ARGS "==%-1u==", 0
//#define ARGS "==%-12u==", LONG_MIN
//#define ARGS "==%-13u==", UINT_MAX
//#define ARGS "==%-13u==", UINT_MAX
//#define ARGS "==%-15u==", 9223372036854775807LL
//#define ARGS "==%-02d==", -1
//#define ARGS "==%-011d==", -1
//#define ARGS "==%-02d==", -1
//#define ARGS "==%+01d==", 111
//#define ARGS "==%+0.1d==", 1
//#define ARGS "==%+01d==", 11
//#define ARGS "==%+0.1d==", 11
//#define ARGS "==%+02d==", 1
//#define ARGS "==%-+10.5d==", 11
//#define ARGS "==%-11d==", LONG_MAX
//#define ARGS "==%-14d==", ULONG_MAX
//#define ARGS "==%04d==", 9
#define ARGS "==% d==", 0

/* 35: 	TEST(10, print(" % d ", 0)); */
/* 37: 	TEST(12, print(" % d ", 1)); */
/* 38: 	TEST(13, print(" % d ", 9)); */
/* 39: 	TEST(14, print(" % d ", 10)); */
/* 40: 	TEST(15, print(" % d ", 11)); */
/* 41: 	TEST(16, print(" % d ", 15)); */
/* 42: 	TEST(17, print(" % d ", 16)); */
/* 43: 	TEST(18, print(" % d ", 17)); */
/* 44: 	TEST(19, print(" % d ", 99)); */
/* 45: 	TEST(20, print(" % d ", 100)); */
/* 46: 	TEST(21, print(" % d ", 101)); */
/* 56: 	TEST(31, print(" % d ", INT_MAX)); */
/* 59: 	TEST(34, print(" % d ", LONG_MIN)); */

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
