/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_is_arrive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:11:21 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 07:59:03 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	philosopers_eats_all(t_philosopher **philosophers)
{
	long			j;
	long			last_philosopher;
	t_philosopher	*p;

	j = 0;
	p = *philosophers;
	last_philosopher = get_num_of_philo(&p[j]) - 1;
	while (get_eat_count(&p[j]) == get_num_of_times_philo_must_eat(&p[j]))
	{
		if (j == last_philosopher)
			return (TRUE);
		j++;
	}
	return (FALSE);
}

int	is_dead_flag_on(t_philosopher *p)
{
	if (lock_is_dead_mutex(p) == FALSE)
		return (FALSE);
	p->philo_args->is_dead = 1;
	printf("%zu %ld died\n", get_current_ms(p), p->x);
	if (unlock_is_dead_mutex(p) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	is_finish(t_philosopher *p)
{
	if (get_is_eat_all_num(p) == get_num_of_philo(p))
		return (TRUE);
	if (get_is_dead(p))
		return (TRUE);
	if (!is_dead_flag_on(p))
		return (TRUE);
	return (FALSE);
}

void	set_stsrt_current(size_t *start, size_t *current, t_philosopher *p)
{
	*start = get_start_eating(p);
	*current = get_current_time();
	if (!*start)
		*start = get_first_eating(p);
}

void	*computation_is_arrive(void *philosophers)
{
	long			i;
	t_philosopher	*p;
	size_t			start;
	size_t			current;

	i = 0;
	p = *((t_philosopher **)philosophers);
	while (1)
	{
		if (philosopers_eats_all(&p))
			return (NULL);
		set_stsrt_current(&start, &current, &p[i]);
		if (start && current - start > get_time_to_die(p))
		{
			if (is_finish(&p[i]) == TRUE)
				return (NULL);
			break ;
		}
		if (get_is_dead(p))
			return (NULL);
		if (++i == get_num_of_philo(p))
			i = 0;
	}
	return (NULL);
}
