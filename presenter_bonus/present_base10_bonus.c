/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_base10_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:12 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 12:50:49 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_base10(t_format *format, va_list *lst)
{
	int		num;
	int		size;

	(void) format;
	num = va_arg(*lst, int);
	ft_putnbr_fd(num, 1);
	if (num <= 0)
		size = 1;
	else
		size = 0;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}
