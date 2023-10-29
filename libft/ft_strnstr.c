/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:55:03 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/26 09:59:46 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char *haystack, char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && haystack[i] && needle[i])
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	if (needle[i] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	else if (needle[0] == '\0')
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		if (is_match((char *) haystack + i, (char *) needle, len - i))
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
