/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:47:46 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/17 13:03:59 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char ch)
{
	return (ch == ' '
		|| ch == '\n'
		|| ch == '\t'
		|| ch == '\r'
		|| ch == '\f'
		|| ch == '\v');
}

static void	parse_spaces(const char **str)
{
	while (is_space(**str))
		(*str)++;
}

static int	parse_sign(const char **str)
{
	if (**str == '+')
	{
		(*str)++;
		return (0);
	}
	else if (**str == '-')
	{
		(*str)++;
		return (1);
	}
	else
		return (0);
}

static const char	*pointer_to_num_end(const char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int			is_negative;
	const char	*num_end;
	int			result;

	parse_spaces(&str);
	is_negative = parse_sign(&str);
	num_end = pointer_to_num_end(str);
	result = 0;
	while (str != num_end)
	{
		result *= 10;
		result += (int)(*str - '0');
		str++;
	}
	if (is_negative)
		return (-result);
	return (result);
}
