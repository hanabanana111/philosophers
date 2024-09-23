/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_with_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:35:11 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 06:00:24 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

size_t	get_first_eating(t_philosopher *p)
{
	size_t	ret;

	pthread_mutex_lock(&p->philo_args->first_eating_mutex);
	ret = p->philo_args->first_eating;
	pthread_mutex_unlock(&p->philo_args->first_eating_mutex);
	return (ret);
}

size_t	get_time_to_die(t_philosopher *p)
{
	size_t	ret;

	pthread_mutex_lock(&p->philo_args->time_to_die_mutex);
	ret = p->philo_args->time_to_die;
	pthread_mutex_unlock(&p->philo_args->time_to_die_mutex);
	return (ret);
}

size_t	get_time_to_eat(t_philosopher *p)
{
	size_t	ret;

	pthread_mutex_lock(&p->philo_args->time_to_eat_mutex);
	ret = p->philo_args->time_to_eat;
	pthread_mutex_unlock(&p->philo_args->time_to_eat_mutex);
	return (ret);
}

size_t	get_time_to_sleep(t_philosopher *p)
{
	size_t	ret;

	pthread_mutex_lock(&p->philo_args->time_to_sleep_mutex);
	ret = p->philo_args->time_to_sleep;
	pthread_mutex_unlock(&p->philo_args->time_to_sleep_mutex);
	return (ret);
}

int	get_is_dead(t_philosopher *p)
{
	int	ret;

	pthread_mutex_lock(&p->philo_args->is_dead_mutex);
	ret = p->philo_args->is_dead;
	pthread_mutex_unlock(&p->philo_args->is_dead_mutex);
	return (ret);
}
