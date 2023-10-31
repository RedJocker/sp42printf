/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:29:27 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 21:44:36 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putnbr_helper(long long nb, char *base, unsigned int base_size)
{
	char	digit;

	if (nb >= base_size)
	{
		ft_putnbr_helper(nb / base_size, base, base_size);
		ft_putnbr_helper(nb % base_size, base, base_size);
	}
	else
	{
		digit = base[nb];
		write(1, &digit, 1);
	}
}

void	init_arr(char *arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void	ft_putnbr_hex(int nbr, int upper, char *base)
{
	char	*p;
	
	
	p = base;
	base_len = 0;
	while (*p != '\0')
	{
		base_len++;
		p++;
	}
	if (!is_valid_base(base, base_len))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_helper(-(long long) nbr, base, base_len);
	}
	else if (nbr == 0)
		write(1, "0", 1);
	else
		ft_putnbr_helper((long long) nbr, base, base_len);
}
