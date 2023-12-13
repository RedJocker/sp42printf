/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_escape_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:51 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/13 18:37:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_escape(t_format *format, va_list *lst)
{
	char	ch;

	(void) format;
	(void) lst;
	ch = '%';
	write(1, &ch, 1);
	return (1);
}
