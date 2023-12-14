/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:40 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/13 21:56:18 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESENTER_BONUS_H
# define PRESENTER_BONUS_H

# include <stdarg.h>
# include "../ft_printf_internals_bonus.h"

int	present_format(t_format *format, va_list *lst);
int	present_string(t_format *format, va_list *lst);
int	present_base10(t_format *format, va_list *lst);
int	present_ubase10(t_format *format, va_list *lst);
int	present_char(t_format *format, va_list *lst);
int	present_escape(t_format *format, va_list *lst);
int	present_hexa_lower(t_format *format, va_list *lst);
int	present_hexa_upper(t_format *format, va_list *lst);
int	present_pointer(t_format *format, va_list *lst);
#endif
