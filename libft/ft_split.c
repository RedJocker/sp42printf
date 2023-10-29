/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:23:16 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/18 18:31:07 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(char const *str, char ch)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != ch)
		{
			count++;
			while (*str && *str != ch)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static void	free_arr(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
}

static void	skip_ch(char const **str, char ch)
{
	while (**str && **str == ch)
		(*str)++;
}

static char	*next_token(char const **str, char ch)
{
	size_t	next_len;
	char	*token;

	skip_ch(str, ch);
	next_len = 0;
	while ((*str)[next_len] && (*str)[next_len] != ch)
		next_len++;
	token = ft_substr(*str, 0, next_len);
	*str += next_len;
	return (token);
}

char	**ft_split(char const *str, char ch)
{
	char	**arr;
	size_t	arr_len;
	size_t	arr_i;

	if (!str)
		return (NULL);
	arr_len = count_splits(str, ch) + 1;
	arr = malloc(arr_len * sizeof(char *));
	if (!arr)
		return (NULL);
	arr_i = 0;
	while (arr_i < arr_len - 1)
	{
		arr[arr_i] = next_token(&str, ch);
		if (!arr[arr_i])
		{
			free_arr(arr);
			return (NULL);
		}
		arr_i++;
	}
	arr[arr_i] = NULL;
	return (arr);
}
