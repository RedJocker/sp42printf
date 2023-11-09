/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:51:58 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:33:24 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"

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
