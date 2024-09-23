/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_digits_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:42:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/20 12:58:42 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	is_arg_digits(char *argv)
{
	size_t	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_args_digits(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (is_arg_digits(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_args_plus(char *argv[])
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
