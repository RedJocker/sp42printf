/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_string_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:53 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 12:50:40 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_string(t_format *format, va_list *lst)
{
	char	*str;
	int		str_len;

	(void) format;
	str = va_arg(*lst, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = (int) ft_strlen(str);
	write(1, str, str_len);
	return (str_len);
}
