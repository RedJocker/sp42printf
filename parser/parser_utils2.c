/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:29:27 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/01 17:01:55 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"

void	ft_putnbr_helper(long long nb, char *base, unsigned int base_size)
{
	char	digit;

	if (nb >= base_size)
	{
		ft_putnbr_helper(nb / base_size, base, base_size);
		ft_putnbr_helper(nb % base_size, base, base_size);
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
		ft_putnbr_helper(-(long long) nbr, hexbase, 16);
	}
	else if (nbr == 0)
		write(1, "0", 1);
	else
		ft_putnbr_helper((long long) nbr, hexbase, 16);
}
