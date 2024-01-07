/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:49 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/07 04:01:10 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	base10_num_size(int nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
		nbr /= 10 + (0 * size++);
	return (size);
}
