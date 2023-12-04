/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:04:23 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/27 16:23:05 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"

int	ft_putnbr_hex(unsigned long long nbr, char *hexbase)
{
	char	digit;
	int		size;

	if (nbr == 0)
		return (write(1, "0", 1));
	size = 0;
	if (nbr >= 16)
	{
		size += ft_putnbr_hex(nbr / 16, hexbase);
		size += ft_putnbr_hex(nbr % 16, hexbase);
	}
	else
	{
		digit = hexbase[nbr];
		size += write(1, &digit, 1);
	}
	return (size);
}
