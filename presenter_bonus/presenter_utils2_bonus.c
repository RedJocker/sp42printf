/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:04:23 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 19:49:15 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include <stdlib.h>

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

void	fill_string(char *str, char filler, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		str[i++] = filler;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}

int		hex_num_size(unsigned long long nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		size = 1;
	else
		while (nbr != 0)
			nbr /= 16 + (0 * size++);
	return (size);
}

void	hex_num_string(char *dest, int size, unsigned long long n, char *xbase)
{
	int					i;

	i = 0;
	if (n == 0)
		dest[0] = '0';
	else
		while (n != 0)
		{
			dest[size - 1 - i++] = xbase[n % 16];
			n /= 16; 
		}
	dest[size] = '\0';
}

