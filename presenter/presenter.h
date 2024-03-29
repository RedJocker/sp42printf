/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:06:04 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/11 21:03:29 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESENTER_H
# define PRESENTER_H

# include <stdarg.h>
# include "ft_printf_internals.h"

int	present_format(t_format *format, va_list *lst);
int	present_string(va_list *lst);
int	present_base10(va_list *lst);
int	present_ubase10(va_list *lst);
int	present_char(va_list *lst);
int	present_escape(va_list *lst);
int	present_hexa_lower(va_list *lst);
int	present_hexa_upper(va_list *lst);
int	present_pointer(va_list *lst);
#endif
