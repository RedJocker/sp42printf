/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_ubase10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:49:23 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:55:11 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_ubase10(va_list *lst)
{
	unsigned int	num;
	int				size;

	num = va_arg(*lst, unsigned int);
	ft_putunbr_fd(num, 1);
	size = 0;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}
