/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:05 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/08 21:58:10 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include <unistd.h>


typedef enum e_flags
{
	NONE = 0,
}	t_flags;

typedef enum e_conversion
{
	INVALID,
	STRING,
	BASE_10,
	UBASE_10,
	CHAR,
	ESCAPE,
}	t_conversion;


// %[flags][width][.precision]conversion
typedef struct s_format
{
	t_flags			flags;
	int				width;
	int 			precision;
	t_conversion	conversion;
}	t_format;

// parser.c
int	parse_format(char **str_ptr, va_list *lst);
int	parse_non_format(char **str_ptr);
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

// parse_format_args.c
int	parse_initial(t_format *format, char **str_ptr);
int	parse_flags(t_format *format, char **str_ptr);
int	parse_width(t_format *format, char **str_ptr);
int	parse_precision(t_format *format, char **str_ptr);
int	parse_convertion(t_format *format, char **str_ptr);

//presenter.c
int	present_format(t_format *format, va_list *lst)

#endif
