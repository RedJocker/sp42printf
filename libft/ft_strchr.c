/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:06:13 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/15 21:24:31 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	char	c;

	c = (char) ch;
	if (*str == c)
		return ((char *)(str));
	while (*str)
	{
		str++;
		if (*str == c)
			return ((char *)(str));
	}
	return (0);
}
