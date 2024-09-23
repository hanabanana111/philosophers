/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 05:10:54 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 05:11:35 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	lock_is_dead_mutex(t_philosopher *p)
{
	if (pthread_mutex_lock(&p->philo_args->is_dead_mutex) != 0)
		return (print_str_error("is_dead mutex lock error\n"), FALSE);
	return (TRUE);
}

int	unlock_is_dead_mutex(t_philosopher *p)
{
	if (pthread_mutex_unlock(&p->philo_args->is_dead_mutex) != 0)
		return (print_str_error("is_dead mutex unlock error\n"), FALSE);
	return (TRUE);
}
