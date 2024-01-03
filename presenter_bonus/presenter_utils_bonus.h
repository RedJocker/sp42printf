/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:50 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/03 06:27:33 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESENTER_UTILS_BONUS_H
# define PRESENTER_UTILS_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf_internals_bonus.h"

# define XBASEL "0123456789abcdef"
# define XBASEU "0123456789ABCDEF"

// presenter_utils_bonus.c
int		ft_putunbr_fd(unsigned int num, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);

// presenter_utils2_bonus.c
int		ft_putnbr_hex(unsigned long long nbr, char *hexbase);
char	*hex_num_string(unsigned long long n, char *xbase, t_format *fmt);
int		hex_num_size(unsigned long long nbr, int precision);

// presenter_utils3_bonus.c
int		pfmt_size_outstr(int xlen, t_format *fmt);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	fill_string(char *str, char filler, unsigned int size);
int		ubase10_num_size(unsigned int nbr, int precision);
int		ubase10_precision(t_format *fmt);

#endif
