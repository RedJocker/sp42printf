/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:01:27 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/18 12:20:10 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	includes(char const *set, char ch)
{
	while (*set)
	{
		if (*set == ch)
			return (1);
		set++;
	}
	return (0);
}

static void	point_start(char const **str, char const *set)
{
	while (includes(set, **str))
		(*str)++;
}

static size_t	trimmed_len(char const *str, char const *set)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	len--;
	while (includes(set, str[len]) && len >= 0)
		len--;
	return (++len);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	size;
	char	*trimmed;

	if (!str)
		return (NULL);
	else if (!set)
		return (ft_strdup(str));
	point_start(&str, set);
	size = trimmed_len(str, set) + 1;
	trimmed = malloc(size * sizeof(char));
	if (trimmed)
		ft_strlcpy(trimmed, str, size);
	return (trimmed);
}
