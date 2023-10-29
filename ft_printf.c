/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:15:46 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/28 22:01:56 by maurodri         ###   ########.fr       */
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

	size = find_ch_or_end_index(*str_ptr, '%') - 1;
	if (size < 0)
		return ;
	write(1, *str_ptr, size);
	*str_ptr = *str_ptr + size;
}

static void parse_number(char **str_ptr, va_list lst)
{
	
}

static int	is_valid_format(char *str)
{
	return (str[0] == '%' && str[1] != '\0');
}

static int	is_number_format(char *str)
{
	return (str[1] == 'd');
}

static void parse_format(char **str_ptr, va_list lst)
{
	if (is_valid_format(*str_ptr))
	{
		if (is_number_format(*str_ptr))
			parse_number(str_ptr, lst);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list ptr;
 	
    va_start(ptr, str);
	
   	
    int arg1 = va_arg(ptr, int);
	char *arg2 = va_arg(ptr, char *);
 	
    va_end(ptr);
	printf("arg1:%d\n", arg1);
	printf("arg2:%s\n", arg2);
 
    return (0);
}
