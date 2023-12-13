/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/12 19:38:46 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf_bonus.h"
//#include "ft_printf_internals_bonus.h"

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
#define ARGS "==% -10p==", (void *) 255
//#define ARGS "==%-9%=="
//#define ARGS "==%19%=="

int	main(void)
{
	int	ret;
	//t_format fmt;

	printf("\nprintf:\n");
	ret = printf(ARGS);
	printf("\nret %i\n", ret);
	printf("\nft_printf:\n");
	ret = ft_printf(ARGS);
	printf("\nret %i\n", ret);
	
	/* fmt.flags = SPACE | LEFT_JUSTIFY; */
	/* printf("%d\n", has_flags(&fmt, 2, SPACE, LEFT_JUSTIFY)); */
	/* printf("%d\n", has_flags(&fmt, 1, SPACE)); */
	/* printf("%d\n", has_flags(&fmt, 1, LEFT_JUSTIFY)); */
	/* printf("%d\n", has_flags(&fmt, 3, SPACE, LEFT_JUSTIFY, HASHTAG)); */
	/* printf("%d\n", has_flags(&fmt, 2, SPACE, HASHTAG)); */
	/* printf("%d\n", has_flags(&fmt, 1, HASHTAG)); */
	return (0);
}
