/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:28:57 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/26 17:02:50 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;
	size_t	sub_size;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		sub = malloc(1 * sizeof(char));
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if ((str_len - start) < len)
		sub_size = str_len - start + 1;
	else
		sub_size = len + 1;
	sub = malloc(sub_size * sizeof(char));
	if (sub)
		ft_strlcpy(sub, str + start, sub_size);
	return (sub);
}
