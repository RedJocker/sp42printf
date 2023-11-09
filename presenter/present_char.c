/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:50:04 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:53:50 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_char(va_list *lst)
{
	char	ch;

	ch = (char) va_arg(*lst, int);
	write(1, &ch, 1);
	return (1);
}
