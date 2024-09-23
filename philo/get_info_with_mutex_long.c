/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_with_mutex_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:14:55 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 06:00:14 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

long	get_is_eat_all_num(t_philosopher *p)
{
	long	ret;

	pthread_mutex_lock(&p->philo_args->is_eat_all_mutex);
	ret = p->philo_args->is_eat_all;
	pthread_mutex_unlock(&p->philo_args->is_eat_all_mutex);
	return (ret);
}

long	get_num_of_philo(t_philosopher *p)
{
	long	ret;

	pthread_mutex_lock(&p->philo_args->num_of_philo_mutex);
	ret = p->philo_args->num_of_philo;
	pthread_mutex_unlock(&p->philo_args->num_of_philo_mutex);
	return (ret);
}

long	get_num_of_times_philo_must_eat(t_philosopher *p)
{
	long	ret;

	pthread_mutex_lock(&p->philo_args->num_of_times_philo_must_eat_mutex);
	ret = p->philo_args->num_of_times_philo_must_eat;
	pthread_mutex_unlock(&p->philo_args->num_of_times_philo_must_eat_mutex);
	return (ret);
}

long	get_is_eat_all(t_philosopher *p)
{
	long	ret;

	pthread_mutex_lock(&p->philo_args->is_eat_all_mutex);
	ret = p->philo_args->is_eat_all;
	pthread_mutex_unlock(&p->philo_args->is_eat_all_mutex);
	return (ret);
}
