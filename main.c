/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 13:15:00 by maurodri         ###   ########.fr       */
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
#define ARGS "==%-c==\n", 'p'

int	main(void)
{
	int	ret;

	printf("\nft_printf:\n");
	ret = ft_printf(ARGS);
	printf("ret %i\n", ret);
	printf("\nprintf:\n");
	ret = printf(ARGS);
	printf("ret %i\n", ret);
	return (0);
}
