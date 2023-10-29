/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:20:05 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/17 11:30:27 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(str) + 1;
	dup = malloc(size * sizeof(char));
	if (dup)
		ft_strlcpy(dup, str, size);
	return (dup);
}
