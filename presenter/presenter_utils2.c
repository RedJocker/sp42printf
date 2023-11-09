/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:33:49 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:37:10 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"

static void	hex_helper(long long nb, char *base, unsigned int base_size)
{
	char	digit;

	if (nb >= base_size)
	{
		hex_helper(nb / base_size, base, base_size); 
		hex_helper(nb % base_size, base, base_size);
	}
	else
	{
		digit = base[nb];
		write(1, &digit, 1);
	}
}

void	ft_putnbr_hex(int nbr, char *hexbase)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		hex_helper(-(long long) nbr, hexbase, 16);
	}
	else if (nbr == 0)
		write(1, "0", 1);
	else
		hex_helper((long long) nbr, hexbase, 16);
}
