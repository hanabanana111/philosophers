/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:40:50 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/20 12:58:46 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	is_oflow(const char *str, int minus)
{
	unsigned long	res;
	unsigned long	ul_max;
	unsigned long	num;

	res = 0;
	num = 0;
	ul_max = (unsigned long)LONG_MAX;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		minus = (*str++ == '-');
	while (*str && ft_isdigit(*str))
	{
		num = *str - '0';
		if (!minus && res > ul_max / 10)
			return (TRUE);
		else if (!minus && res == ul_max / 10 && num > ul_max % 10)
			return (TRUE);
		else if (minus && res > ul_max / 10)
			return (TRUE);
		else if (minus && res == ul_max / 10 && num > (ul_max + 1) % 10)
			return (TRUE);
		res = res * 10 + *str++ - '0';
	}
	return (FALSE);
}

int	is_args_overflow(char *argv[])
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (is_oflow(argv[i], 0))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
