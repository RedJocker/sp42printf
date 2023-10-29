/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:19:39 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/19 13:31:15 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*fun)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!str)
		return (NULL);
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = fun(i, new_str[i]);
		i++;
	}
	return (new_str);
}
