/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:00:34 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 08:00:56 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	*computation(void *philosophers)
{
	t_philosopher	*p;
	long			y;
	long			num_of_philo;

	p = (t_philosopher *)philosophers;
	num_of_philo = get_num_of_philo(p);
	y = p->x + 1;
	if (p->x % 2 == 1)
		usleep(10000);
	if (p->x + 1 == num_of_philo)
		y = 0;
	while (1)
	{
		if (treat_eat(&p, y, num_of_philo) == FALSE)
			break ;
		if (treat_sleep(p, num_of_philo) == FALSE)
			break ;
		if (treat_think(p, num_of_philo) == FALSE)
			break ;
	}
	return (NULL);
}

int	treat_thread(t_philosopher *philosophers)
{
	long		i;
	pthread_t	is_arrive;

	i = 0;
	if (set_value_first_eating(philosophers) == FALSE)
		return (FALSE);
	while (i < get_num_of_philo(philosophers))
	{
		if (pthread_create(&philosophers[i].thread, NULL, computation,
				(void *)&philosophers[i]) != 0)
			return (write(2, "pthread_create error\n", 21), FALSE);
		i++;
	}
	if (pthread_create(&is_arrive, NULL, computation_is_arrive,
			(void *)&philosophers) != 0)
		return (write(2, "is_arrive pthread_create error\n", 21), FALSE);
	i = 0;
	while (i < get_num_of_philo(philosophers))
		if (pthread_join(philosophers[i++].thread, NULL) != 0)
			return (print_str_error("pthread_join error\n"), FALSE);
	if (pthread_join(is_arrive, NULL) != 0)
		return (print_str_error("is_arrive pthread_join error\n"), FALSE);
	return (TRUE);
}
