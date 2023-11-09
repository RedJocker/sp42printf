/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/08 23:48:33 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define ARGS "==%d%s%c%i%%%u==\n", -200, "HELLO", '?', 19, -1
//#define ARGS "==%s==\n", "HELLO"
//#define ARGS "==%d==\n", -200
//#define ARGS "==%i==\n", 12345
//#define ARGS "==%u==\n", -1
//#define ARGS "==%%==\n"
//#define ARGS "==%c==\n", '?'

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
