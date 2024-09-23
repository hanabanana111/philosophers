/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:58:52 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 07:18:44 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

size_t	get_current_time(void)
{
	size_t			current_time_ms;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		print_str_error("gettimeofday function error\n");
	current_time_ms = (size_t)current_time.tv_usec / 1000 + current_time.tv_sec
		* 1000;
	return (current_time_ms);
}

size_t	get_current_ms(t_philosopher *philosophers)
{
	size_t	current_ms;
	size_t	start;

	start = get_first_eating(philosophers);
	if (!start)
	{
		pthread_mutex_lock(&philosophers->philo_args->first_eating_mutex);
		philosophers->philo_args->first_eating = get_current_time();
		pthread_mutex_unlock(&philosophers->philo_args->first_eating_mutex);
		start = get_first_eating(philosophers);
	}
	current_ms = (get_current_time() - start);
	return (current_ms);
}

int	count_time(t_philosopher **philosophers, int status)
{
	t_philosopher	*p;
	size_t			start;
	size_t			max_count;

	p = *philosophers;
	start = 0;
	max_count = 0;
	if (status == EAT)
	{
		start = get_start_eating(p);
		max_count = get_time_to_eat(p);
	}
	else if (status == SLEEP)
	{
		start = get_start_sleeping(p);
		max_count = get_time_to_sleep(p);
	}
	while (get_current_time() - start < max_count)
	{
		if (get_is_dead(p) || get_is_eat_all(p) == get_num_of_philo(p))
			return (FALSE);
		usleep(100);
	}
	return (TRUE);
}
