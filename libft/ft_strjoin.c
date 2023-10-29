/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:11:37 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/18 12:21:45 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len1;
	size_t	len2;
	char	*str_join;

	if (!str1 && !str2)
		return (NULL);
	else if (!str1)
		return (ft_strdup(str2));
	else if (!str2)
		return (ft_strdup(str1));
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	str_join = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	ft_memcpy(str_join, str1, len1);
	ft_strlcpy(str_join + len1, str2, len2 + 1);
	return (str_join);
}
