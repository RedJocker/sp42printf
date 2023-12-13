/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:08:40 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/13 18:45:43 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals_bonus.h"
#include <stdarg.h>

int	has_flags(t_format *fmt, int num_flags, ...)
{
	int		i;
	int		has_all_flags;
	t_flags	flag;
	va_list	lst;

	has_all_flags = 1;
	va_start(lst, num_flags);
	i = 0;
	while (i < num_flags)
	{
		flag = va_arg(lst, t_flags);
		if ((fmt->flags & flag) != flag)
		{
			has_all_flags = 0;
			break ;
		}
		i++;
	}
	va_end(lst);
	return (has_all_flags);
}
