/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:52:14 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:06:48 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include <unistd.h>
# include <stdlib.h>

// parser_utils.c
int		find_ch_or_end_index(char *str, char ch);
int		ft_putunbr_fd(unsigned int num, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
//

#endif
