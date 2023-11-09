/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:10:50 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/09 00:18:36 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNALS_H
# define FT_PRINTF_INTERNALS_H

typedef enum e_flags
{
	NONE = 0,
}	t_flags;

typedef enum e_conversion
{
	INVALID,
	STRING,
	BASE_10,
	UBASE_10,
	CHAR,
	ESCAPE,
}	t_conversion;

// %[flags][width][.precision]conversion
typedef struct s_format
{
	t_flags			flags;
	int				width;
	int				precision;
	t_conversion	conversion;
}	t_format;

#endif