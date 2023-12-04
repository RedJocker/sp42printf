/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_hexa_lower_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:51 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 12:51:22 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_hexa_lower(t_format *format, va_list *lst)
{
	unsigned int	num;

	(void) format;	
	num = va_arg(*lst, unsigned int);
	return (ft_putnbr_hex(num, "0123456789abcdef"));
}
