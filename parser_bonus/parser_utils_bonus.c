/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:16 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/27 16:10:16 by maurodri         ###   ########.fr       */
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
