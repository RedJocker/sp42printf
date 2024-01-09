/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:50 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/08 19:49:31 by maurodri         ###   ########.fr       */
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
size_t	ft_strlen(const char *str);
int		base10_num_size(int nbr);

// presenter_utils2_bonus.c
int		fill_hex_num(char *num_str, unsigned long long n, int size, char *xbase);
char	*pointer_hex_num_string(unsigned long long n, char *xbase, t_format *fmt);
int		hex_num_size(unsigned long long nbr, int precision);
char	*hex_num_string(unsigned int n, char *xbase, t_format *fmt);

// presenter_utils3_bonus.c
int		pointer_size_outstr(int xlen, t_format *fmt);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	fill_string(char *str, char filler, unsigned int size);
int		ubase10_num_size(unsigned int nbr, int precision);
int		ubase10_precision(t_format *fmt);

#endif
