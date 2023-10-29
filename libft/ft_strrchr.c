/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:05:34 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/15 21:22:38 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	char	*ptr;
	char	c;

	c = (char) ch;
	ptr = (char *) str;
	while (*ptr)
		ptr++;
	if (c == '\0')
		return (ptr);
	while (ptr >= str)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
	}
	return (0);
}
