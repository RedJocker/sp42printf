/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_hexa_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:55:20 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/16 15:37:27 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_hexa_upper(va_list *lst)
{
	unsigned int	num;

	num = va_arg(*lst, unsigned int);
	return (ft_putnbr_hex(num, "0123456789ABCDEF"));
}
