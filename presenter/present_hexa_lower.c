/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_hexa_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:46 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:41 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_hexa_lower(va_list *lst)
{
	unsigned int	num;

	num = va_arg(*lst, unsigned int);
	return (ft_putnbr_hex(num, "0123456789abcdef"));
}
