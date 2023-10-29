/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:55:02 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/15 00:45:58 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (src < dst && ((size_t)(dst - src)) < len)
	{
		i = ((int) len) - 1;
		while (i >= 0)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
