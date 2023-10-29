/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:03:12 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/24 15:03:14 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *node, void (*del_content)(void*))
{
	if (!node || !del_content)
		return ;
	if (node->content)
		del_content(node->content);
	free(node);
}
