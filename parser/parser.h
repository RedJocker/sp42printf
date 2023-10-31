/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:05 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 21:44:36 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <unistd.h>

// parser.c
int	parse_format(char **str_ptr, va_list *lst);
int	parse_non_format(char **str_ptr);
int	is_valid_format(char *str);
// parser_string.c
int	is_string_format(char *str);
int	parse_string(char **str_ptr, va_list *lst);
// parser_ubase10.c
int	is_ubase10_format(char *str);
int	parse_ubase10(char **str_ptr, va_list *lst);
// parser_base10.c
int	is_base10_format(char *str);
int	parse_base10(char **str_ptr, va_list *lst);
// parser_char.c
int	is_char_format(char *str);
int	parse_char(char **str_ptr, va_list *lst);
// parser_escape.c
int	is_escape_format(char *str);
int	parse_escape(char **str_ptr, va_list *lst);


#endif
