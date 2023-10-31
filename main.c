/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:42:55 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:19:23 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define ARGS "==%d%s%c%i%%%u==\n", -200, "HELLO", '?', 19, -1

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
