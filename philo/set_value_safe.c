/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:24:49 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 07:59:55 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	set_value_first_eating(t_philosopher *p)
{
	if (pthread_mutex_lock(&p->philo_args->first_eating_mutex) != 0)
		return (FALSE);
	p->philo_args->first_eating = get_current_time();
	if (pthread_mutex_unlock(&p->philo_args->first_eating_mutex) != 0)
		return (FALSE);
	return (TRUE);
}

int	set_value_start_eating(t_philosopher *p)
{
	if (pthread_mutex_lock(&p->start_eating_mutex) != 0)
		return (FALSE);
	p->start_eating = get_current_time();
	if (pthread_mutex_unlock(&p->start_eating_mutex) != 0)
		return (FALSE);
	return (TRUE);
}

int	set_value_eat_count(t_philosopher *p)
{
	if (pthread_mutex_lock(&p->eat_count_mutex) != 0)
		return (FALSE);
	p->eat_count++;
	if (pthread_mutex_unlock(&p->eat_count_mutex) != 0)
		return (FALSE);
	return (TRUE);
}

int	set_value_is_eat_all(t_philosopher *p)
{
	if (pthread_mutex_lock(&p->eat_count_mutex) != 0)
		return (FALSE);
	if (p->eat_count == get_num_of_times_philo_must_eat(p))
	{
		if (pthread_mutex_lock(&p->philo_args->is_eat_all_mutex) != 0)
			return (pthread_mutex_unlock(&p->eat_count_mutex), FALSE);
		p->philo_args->is_eat_all++;
		if (pthread_mutex_unlock(&p->philo_args->is_eat_all_mutex) != 0)
			return (pthread_mutex_unlock(&p->eat_count_mutex), FALSE);
	}
	if (pthread_mutex_unlock(&p->eat_count_mutex) != 0)
		return (print_str_error("is_eat_all mutex lock error\n"), FALSE);
	return (TRUE);
}
