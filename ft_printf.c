/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:15:46 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/29 13:38:36 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

int	ft_printf(const char *str, ...);

int	main(void)
{
	
	ft_printf("==%d %s==", 2, "HELLO");
	return (0);
}

static ssize_t	find_ch_or_end_index(char *str, char ch)
{
	ssize_t	i;

	i = 0;
	while (str[i] && str[i] != ch)
	{
		i++;
	}
	return (i);
}

static void parse_non_format(char **str_ptr)
{
	ssize_t	size;

	size = find_ch_or_end_index(*str_ptr, '%');
	write(1, *str_ptr, size);
	*str_ptr = *str_ptr + size;
}

static void parse_number(char **str_ptr, va_list *lst)
{
	int		num;
	
	num = va_arg(*lst, int);
	ft_putnbr_fd(num, 1);
	*str_ptr = *str_ptr + 2; 
}

static void	parse_string(char **str_ptr, va_list *lst)
{
	char	*str;
	size_t	str_len;
	
	str = va_arg(*lst, char *);
	ft_putstr_fd(str, 1);
	*str_ptr = *str_ptr + 2;
}

static int	is_valid_format(char *str)
{
	return (str[0] == '%' && str[1] != '\0');
}

static int	is_number_format(char *str)
{
	return (str[1] == 'd');
}

static int	is_string_format(char *str)
{
	return (str[1] == 's');
}

static void parse_format(char **str_ptr, va_list *lst)
{
	if (is_valid_format(*str_ptr))
	{
		if (is_number_format(*str_ptr))
			parse_number(str_ptr, lst);
		else if (is_string_format(*str_ptr))
			parse_string(str_ptr, lst);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list args;
 	
    va_start(args, str);
	while (*str)
	{
		parse_non_format((char **)&str);
		parse_format((char **)&str, &args);
	}
   	
    va_end(args); 
    return (0);
}
