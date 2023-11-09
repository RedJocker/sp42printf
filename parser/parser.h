/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:05 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:15:14 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <unistd.h>
# include "../ft_printf_internals.h"

// parser.c
int	parse_format(char **str_ptr, va_list *lst);
int	parse_non_format(char **str_ptr);

// parse_format_args.c
int	parse_initial(t_format *format, char **str_ptr);
int	parse_flags(t_format *format, char **str_ptr);
int	parse_width(t_format *format, char **str_ptr);
int	parse_precision(t_format *format, char **str_ptr);
int	parse_convertion(t_format *format, char **str_ptr);

#endif
