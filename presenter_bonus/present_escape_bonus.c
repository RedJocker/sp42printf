/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_escape_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:51 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/08 23:55:06 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_escape(t_format *format, va_list *lst)
{
	char	ch;
	int		i;
	
	(void) lst;
	ch = '%';
	if (format->width <= 1)
	{
		write(1, &ch, 1);
		return (1);
	}
	else
	{
		i = 1;
		if ((format->flags & LEFT_JUSTIFY) == LEFT_JUSTIFY)
		{
			write(1, &ch, 1);
			ch = ' ';
			while (i++ < format->width)
				write(1, &ch, 1);
		}
		else
		{
			ch = ' ';
			while (i++ < format->width)
				write(1, &ch, 1);
			ch = '%';
			write(1, &ch, 1);
		}
		return (format->width);	
	}
}
