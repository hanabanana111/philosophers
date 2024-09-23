/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dead_and_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:15:32 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 07:45:47 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	print_message(t_philosopher *p, char *str)
{
	if (pthread_mutex_lock(&p->philo_args->is_dead_mutex) != 0)
		return (FALSE);
	if (!p->philo_args->is_dead)
		printf("%zu %ld %s\n", get_current_ms(p), p->x, str);
	else
		return (pthread_mutex_unlock(&p->philo_args->is_dead_mutex), FALSE);
	if (pthread_mutex_unlock(&p->philo_args->is_dead_mutex) != 0)
		return (FALSE);
	return (TRUE);
}
