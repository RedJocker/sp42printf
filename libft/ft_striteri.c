/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:33:14 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/19 13:48:51 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_striteri(char *str, void (*fun)(unsigned int, char*))
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		fun(i, str + i);
		i++;
	}
}
