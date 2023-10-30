/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:15:46 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:40 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

#define ARGS "==%d%s%c%i%%==\n", -200, "HELLO", '?', 19

int	ft_printf(const char *str, ...);

int	main(void)
{
	int ret;
	
	printf("\nft_printf:\n");
	ret = ft_printf(ARGS);
	printf("ret %i\n", ret);
	printf("\nprintf:\n");
	ret = printf(ARGS);
	printf("ret %i\n", ret);
	return (0);
}

static int	find_ch_or_end_index(char *str, char ch)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ch)
	{
		i++;
	}
	return (i);
}

static int	parse_non_format(char **str_ptr)
{
	int	size;

	size = find_ch_or_end_index(*str_ptr, '%');
	write(1, *str_ptr, size);
	*str_ptr = *str_ptr + size;
	return (size);
}

static int	parse_escape(char **str_ptr, va_list *lst)
{
	char	ch;

	(void) lst;
	ch = '%';
	ft_putchar_fd(ch, 1);
	*str_ptr = *str_ptr + 2;
	return (1);
}

static int	parse_char(char **str_ptr, va_list *lst)
{
	char	ch;

	ch = (char) va_arg(*lst, int);
	ft_putchar_fd(ch, 1);
	*str_ptr = *str_ptr + 2;
	return (1);
}

static int	parse_number(char **str_ptr, va_list *lst)
{
	int		num;
	int		size;
	
	num = va_arg(*lst, int);
	ft_putnbr_fd(num, 1);
	*str_ptr = *str_ptr + 2;
	if (num <= 0)
		size = 1;
	else
		size = 0;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}

static int	parse_string(char **str_ptr, va_list *lst)
{
	char	*str;
	int		str_len;
	
	str = va_arg(*lst, char *);
	str_len = (int) ft_strlen(str);
	ft_putstr_fd(str, 1);
	*str_ptr = *str_ptr + 2;
	return (str_len);
}

static int	is_valid_format(char *str)
{
	return (str[0] == '%' && str[1] != '\0');
}

static int	is_escape_format(char *str)
{
	return	(str[1] == '%');
}

static int	is_char_format(char *str)
{
	return (str[1] == 'c');
}

static int	is_base10_format(char *str)
{
	return (str[1] == 'd' || str[1] == 'i');
}

static int	is_string_format(char *str)
{
	return (str[1] == 's');
}

static int	parse_format(char **str_ptr, va_list *lst)
{
	int	len;

	len = 0;
	if (is_valid_format(*str_ptr))
	{
		if (is_base10_format(*str_ptr))
			len = parse_number(str_ptr, lst);
		else if (is_string_format(*str_ptr))
			len = parse_string(str_ptr, lst);
		else if (is_char_format(*str_ptr))
			len = parse_char(str_ptr, lst);
		else if (is_escape_format(*str_ptr))
			len = parse_escape(str_ptr, lst);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		len;
 	
    va_start(args, str);
	len = 0;
	while (*str)
	{
		len += parse_non_format((char **)&str);
		len += parse_format((char **)&str, &args);
	}
   	
    va_end(args); 
    return (len);
}
