/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:54:50 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/23 18:11:26 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *block1, const void *block2, size_t len)
{
	if (len == 0)
		return (0);
	while (len > 1 && *((unsigned char *)block1) == *((unsigned char *)block2))
	{
		block1++;
		block2++;
		len--;
	}
	return (*((unsigned char *)block1) - *((unsigned char *)block2));
}
