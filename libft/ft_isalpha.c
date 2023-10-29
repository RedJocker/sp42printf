/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:50:07 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/14 17:43:18 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_isupper(int ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

static inline int	ft_islower(int ch)
{
	return (ch >= 'a' && ch <= 'z');
}

int	ft_isalpha(int ch)
{
	return (ft_isupper(ch) || ft_islower(ch));
}
