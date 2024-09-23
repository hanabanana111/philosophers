/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork_odd_even.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 06:57:51 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 07:59:23 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	odd_fork(t_philosopher *p, long y)
{
	if (pthread_mutex_lock(&p->philo_args->forks[p->x]) != 0)
		return (print_str_error("fork mutex lock error\n"), FALSE);
	if (print_message(p, "has taken a fork") == FALSE)
		return (pthread_mutex_unlock(&p->philo_args->forks[p->x]), FALSE);
	if (p->x == y || get_is_dead(p))
		return (pthread_mutex_unlock(&p->philo_args->forks[p->x]), (FALSE));
	if (pthread_mutex_lock(&p->philo_args->forks[y]) != 0)
	{
		if (pthread_mutex_unlock(&p->philo_args->forks[p->x]) != 0)
			return (print_str_error("fork mutex unlock error\n"), FALSE);
		return (print_str_error("fork mutex lock error\n"), FALSE);
	}
	if (get_is_dead(p) || print_message(p, "has taken a fork") == FALSE)
	{
		pthread_mutex_unlock(&p->philo_args->forks[p->x]);
		return (pthread_mutex_unlock(&p->philo_args->forks[y]), FALSE);
	}
	return (TRUE);
}

int	even_fork(t_philosopher *p, long y)
{
	if (pthread_mutex_lock(&p->philo_args->forks[y]) != 0)
		return (print_str_error("fork mutex lock error\n"), FALSE);
	if (print_message(p, "has taken a fork") == FALSE)
		return (pthread_mutex_unlock(&p->philo_args->forks[y]), FALSE);
	if (y == p->x || get_is_dead(p))
		return (pthread_mutex_unlock(&p->philo_args->forks[y]), (FALSE));
	if (pthread_mutex_lock(&p->philo_args->forks[p->x]) != 0)
	{
		if (pthread_mutex_unlock(&p->philo_args->forks[y]) != 0)
			return (print_str_error("fork mutex unlock error\n"), FALSE);
		return (print_str_error("fork mutex lock error\n"), FALSE);
	}
	if (get_is_dead(p) || print_message(p, "has taken a fork") == FALSE)
	{
		pthread_mutex_unlock(&p->philo_args->forks[y]);
		return (pthread_mutex_unlock(&p->philo_args->forks[p->x]), FALSE);
	}
	return (TRUE);
}
