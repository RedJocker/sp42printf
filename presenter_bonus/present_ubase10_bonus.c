/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_ubase10_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:54 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 12:50:59 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_ubase10(t_format *format, va_list *lst)
{
	unsigned int	num;
	int				size;

	(void) format;
	num = va_arg(*lst, unsigned int);
	ft_putunbr_fd(num, 1);
	if (num == 0)
		return (1);
	size = 0;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}
