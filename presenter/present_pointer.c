/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:05:29 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/17 18:48:33 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_pointer(va_list *lst)
{
	void	*num;

	num = va_arg(*lst, void *);
	if (!num)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putnbr_hex((unsigned long long)num, "0123456789abcdef"));
}
