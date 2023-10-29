/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:58:17 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/15 19:01:32 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	char	c;

	c = (char) ch;
	if (c >= 'A' && c <= 'Z')
		return (ch + 32);
	else
		return (ch);
}
