/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philosopher_under_200.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:48:26 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/20 12:59:54 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	is_philosoper_under_200(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num > 200 || num < 1)
		return (FALSE);
	return (TRUE);
}
