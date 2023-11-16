/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:43:42 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/16 14:02:38 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_string(va_list *lst)
{
	char	*str;
	int		str_len;

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
