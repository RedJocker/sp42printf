/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:10:50 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/10 00:57:35 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNALS_BONUS_H
# define FT_PRINTF_INTERNALS_BONUS_H

typedef enum e_flags
{
	NONE = 0,
	LEFT_JUSTIFY = 1,
	ZERO_PAD = 2,
	SIGNED = 4,
	SPACE = 8,
	HASHTAG = 16,
}	t_flags;

typedef enum e_conversion
{
	INVALID,
	STRING,
	BASE_10,
	UBASE_10,
	CHAR,
	ESCAPE,
	HEXA_LOWER,
	HEXA_UPPER,
	POINTER
}	t_conversion;

// %[flags][width][.precision]conversion
typedef struct s_format
{
	int				flags;
	int				width;
	int				precision;
	t_conversion	conversion;
}	t_format;

int	has_flags(t_format *fmt, int num_flags, ...);
#endif
