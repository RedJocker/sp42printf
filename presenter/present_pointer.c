/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:05:29 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/16 15:37:57 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_pointer(va_list *lst)
{
	void	*num;

	num = va_arg(*lst, void *);
	write(1, "0x", 2);
	return (2 + ft_putnbr_hex((unsigned long)num, "0123456789abcdef"));
}
