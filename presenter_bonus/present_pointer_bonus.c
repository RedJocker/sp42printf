/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:52 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 12:53:04 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_pointer(t_format *format, va_list *lst)
{
	void	*num;

	(void) format;
	num = va_arg(*lst, void *);
	if (!num)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putnbr_hex((unsigned long long)num, "0123456789abcdef"));
}
