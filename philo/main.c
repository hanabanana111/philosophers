/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 07:57:53 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/22 00:08:05 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	philo_struct_init(char *argv[], t_philo_args *philo_args)
{
	philo_args->num_of_philo = ft_atoi(argv[1]);
	philo_args->time_to_die = ft_atoi(argv[2]);
	philo_args->time_to_eat = ft_atoi(argv[3]);
	philo_args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo_args->num_of_times_philo_must_eat = ft_atoi(argv[5]);
	else
		philo_args->num_of_times_philo_must_eat = -1;
	philo_args->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t),
			philo_args->num_of_philo);
	if (!philo_args->forks)
		return (FALSE);
	pthread_mutex_init(&philo_args->num_of_philo_mutex, NULL);
	pthread_mutex_init(&philo_args->first_eating_mutex, NULL);
	pthread_mutex_init(&philo_args->time_to_die_mutex, NULL);
	pthread_mutex_init(&philo_args->time_to_eat_mutex, NULL);
	pthread_mutex_init(&philo_args->time_to_sleep_mutex, NULL);
	pthread_mutex_init(&philo_args->num_of_times_philo_must_eat_mutex, NULL);
	pthread_mutex_init(&philo_args->is_dead_mutex, NULL);
	pthread_mutex_init(&philo_args->is_eat_all_mutex, NULL);
	philo_args->is_dead = 0;
	philo_args->is_eat_all = 0;
	return (TRUE);
}

int	philosphers_init(t_philosopher **philosophers, t_philo_args *philo_args)
{
	long			i;
	t_philosopher	*p;

	i = 0;
	*philosophers = (t_philosopher *)ft_calloc(sizeof(t_philosopher),
			philo_args->num_of_philo + 1);
	if (!(*philosophers))
		return (FALSE);
	p = *philosophers;
	while (i < philo_args->num_of_philo)
	{
		p->x = i;
		p->philo_args = philo_args;
		p->start_eating = 0;
		pthread_mutex_init(&philo_args->forks[i], NULL);
		pthread_mutex_init(&p->eat_count_mutex, NULL);
		pthread_mutex_init(&p->start_eating_mutex, NULL);
		pthread_mutex_init(&p->start_sleeping_mutex, NULL);
		p++;
		i++;
	}
	return (TRUE);
}

int	check_argv(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (print_str_error("Invalid arguments.\n"), FALSE);
	if (is_args_digits(&argv[1]) == FALSE)
		return (print_str_error("arguments should be numbers.\n"), FALSE);
	if (is_args_plus(&argv[1]) == FALSE)
		return (print_str_error("arguments should be non negative numbers.\n"),
			FALSE);
	if (is_args_overflow(&argv[1]) == TRUE)
		return (print_str_error("arguments number overflow.\n"), FALSE);
	if (is_philosoper_under_200(argv[1]) == FALSE)
		return (print_str_error("Invalid number of philosopers.\n"), FALSE);
	return (TRUE);
}

void	free_philo_args(t_philo_args *p_args, t_philosopher *philosophers)
{
	free(p_args->forks);
	free(philosophers);
}

int	main(int argc, char *argv[])
{
	t_philosopher	*philosophers;
	t_philo_args	philo_args;

	philosophers = NULL;
	ft_bzero(&philo_args, sizeof(t_philo_args));
	if (check_argv(argc, argv) == FALSE)
		return (1);
	if (!philo_struct_init(argv, &philo_args))
		return (print_str_error("init error\n"), 1);
	if (!philosphers_init(&philosophers, &philo_args))
		return (free_philo_args(&philo_args, philosophers), 1);
	if (!treat_thread(philosophers))
		return (free_philo_args(&philo_args, philosophers),
			print_str_error("thread error\n"), 1);
	free_philo_args(&philo_args, philosophers);
	return (0);
}
