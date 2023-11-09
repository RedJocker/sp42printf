/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:28:12 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:33:17 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESENTER_UTILS_H
# define PRESENTER_UTILS_H

# include <unistd.h>

// presenter_utils.c
int		ft_putunbr_fd(unsigned int num, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);

// presenter_utils2.c
void	ft_putnbr_hex(int nbr, char *hexbase);

#endif
