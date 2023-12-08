/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:50 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/07 22:33:24 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESENTER_UTILS_BONUS_H
# define PRESENTER_UTILS_BONUS_H

# include <unistd.h>
# define XBASEL "0123456789abcdef"
# define XBASEU "0123456789ABCDEF"

// presenter_utils_bonus.c
int		ft_putunbr_fd(unsigned int num, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);

// presenter_utils2_bonus.c
int		ft_putnbr_hex(unsigned long long nbr, char *hexbase);
void	fill_string(char *str, char filler, unsigned int size);
char 	*hex_num_string(unsigned long long n, char *xbase, int precision);
int		hex_num_size(unsigned long long nbr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
