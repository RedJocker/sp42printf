/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_base10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:45:22 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:54:21 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_base10(va_list *lst)
{
	int		num;
	int		size;

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
