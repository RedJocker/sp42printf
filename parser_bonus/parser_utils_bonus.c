/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:16 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/14 16:29:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils_bonus.h"

int	find_ch_or_end_index(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
	{
		i++;
	}
	return (i);
}

int	parse_number(char **str)
{
	int	num;

	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		num = (num * 10) + (**str - '0');
		(*str)++;
	}
	return (num);
}

int	parse_number_precision(char **str)
{
	int	num;

	num = -1;
	if (**str >= '0' && **str <= '9')
	{
		num = parse_number(str);
		if (num == 0)
			num = -1;
	}
	return (num);
}
