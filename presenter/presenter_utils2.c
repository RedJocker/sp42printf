/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:33:49 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/17 18:46:12 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"

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
