/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_escape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:50:59 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:56:18 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_escape(va_list *lst)
{
	char	ch;

	(void) lst;
	ch = '%';
	write(1, &ch, 1);
	return (1);
}
