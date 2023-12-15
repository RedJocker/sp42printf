/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/14 18:26:10 by maurodri         ###   ########.fr       */
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
#define ARGS "==%-12u==", LONG_MIN

//117: 	TEST(87, print(" %-1u ", 0));
//141: 	TEST(111, print(" %-12u ", LONG_MIN));
//142: 	TEST(112, print(" %-13u ", UINT_MAX));
//144: 	TEST(114, print(" %-15u ", 9223372036854775807LL));
//145: 	TEST(115, print(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
//84: 	TEST(57, print(" %01u ", 0));
//108: 	TEST(81, print(" %012u ", LONG_MIN));
//109: 	TEST(82, print(" %013u ", UINT_MAX));
//111: 	TEST(84, print(" %015u ", 9223372036854775807LL));
//112: 	TEST(85, print(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
//118: 	TEST(91, print(" %.10u ", LONG_MAX));
//119: 	TEST(92, print(" %.11u ", LONG_MIN));
//121: 	TEST(94, print(" %.13u ", ULONG_MAX));
//122: 	TEST(95, print(" %.14u ", 9223372036854775807LL));
//123: 	TEST(96, print(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
//
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
