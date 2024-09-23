/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_eat_sleep_think.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:23:54 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 08:00:12 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	lock_fork_mutexs(t_philosopher *p, long y)
{
	if (p->x % 2 == 1)
		if (odd_fork(p, y) == FALSE)
			return (FALSE);
	if (p->x % 2 == 0)
		if (even_fork(p, y) == FALSE)
			return (FALSE);
	return (TRUE);
}

int	unlock_fork_mutexs(t_philosopher *p, long y)
{
	if (pthread_mutex_unlock(&p->philo_args->forks[p->x]) != 0)
		return (print_str_error("fork mutex unlock error\n"), FALSE);
	if (pthread_mutex_unlock(&p->philo_args->forks[y]) != 0)
		return (print_str_error("fork mutex unlock error\n"), FALSE);
	return (TRUE);
}

int	treat_eat(t_philosopher **philosophers, long y, long num_of_philo)
{
	t_philosopher	*p;

	p = *philosophers;
	if (get_is_dead(p) || get_is_eat_all_num(p) == num_of_philo)
		return (FALSE);
	if (lock_fork_mutexs(p, y) == FALSE)
		return (FALSE);
	if (set_value_start_eating(p) == FALSE)
		return (unlock_fork_mutexs(p, y), FALSE);
	if (print_message(p, "is eating") == FALSE)
		return (unlock_fork_mutexs(p, y), FALSE);
	if (count_time(philosophers, EAT) == FALSE)
		return (unlock_fork_mutexs(p, y), FALSE);
	if (unlock_fork_mutexs(p, y) == FALSE)
		return (FALSE);
	if (set_value_eat_count(p) == FALSE)
		return (FALSE);
	if (set_value_is_eat_all(p) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	treat_sleep(t_philosopher *p, long num_of_philo)
{
	if (get_is_eat_all_num(p) == num_of_philo)
		return (FALSE);
	pthread_mutex_lock(&p->start_sleeping_mutex);
	p->start_sleeping = get_current_time();
	pthread_mutex_unlock(&p->start_sleeping_mutex);
	if (print_message(p, "is sleeping") == FALSE)
		return (FALSE);
	if (count_time(&p, SLEEP) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	treat_think(t_philosopher *p, long num_of_philo)
{
	if (get_is_eat_all_num(p) == num_of_philo)
		return (FALSE);
	if (print_message(p, "is thinking") == FALSE)
		return (FALSE);
	return (TRUE);
}
