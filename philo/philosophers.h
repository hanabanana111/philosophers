/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 07:57:56 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 07:54:24 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

# define EAT 0
# define SLEEP 1

typedef struct s_philo_args
{
	long			num_of_philo;
	pthread_mutex_t	num_of_philo_mutex;
	size_t			first_eating;
	pthread_mutex_t	first_eating_mutex;
	size_t			time_to_die;
	pthread_mutex_t	time_to_die_mutex;
	size_t			time_to_eat;
	pthread_mutex_t	time_to_eat_mutex;
	size_t			time_to_sleep;
	pthread_mutex_t	time_to_sleep_mutex;
	long			num_of_times_philo_must_eat;
	pthread_mutex_t	num_of_times_philo_must_eat_mutex;
	pthread_mutex_t	*forks;
	int				is_dead;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	is_eat_all_mutex;
	long			is_eat_all;
}					t_philo_args;

typedef struct s_philosopher
{
	long			x;
	long			eat_count;
	pthread_mutex_t	eat_count_mutex;
	size_t			start_eating;
	pthread_mutex_t	start_eating_mutex;
	size_t			start_sleeping;
	pthread_mutex_t	start_sleeping_mutex;
	pthread_t		thread;
	t_philo_args	*philo_args;
}					t_philosopher;

// args_overflow.c
int					is_oflow(const char *str, int minus);
int					is_args_overflow(char *argv[]);

// args_digits_plus.c
int					is_arg_digits(char *argv);
int					is_args_digits(char **argv);
int					is_args_plus(char *argv[]);

// is_philosopher_under_200.c
int					is_philosoper_under_200(char *str);

// treat_thread.c
int					treat_thread(t_philosopher *philosophers);

// thread_eat_sleep_think.c
int					treat_eat(t_philosopher **philosophers, long y,
						long num_of_philo);
int					treat_sleep(t_philosopher *p, long num_of_philo);
int					treat_think(t_philosopher *p, long num_of_philo);

// get_time.c
size_t				get_current_time(void);
size_t				get_current_ms(t_philosopher *philosophers);
int					count_time(t_philosopher **philosophers, int status);

// thread_is_arrive.c
void				*computation_is_arrive(void *philosophers);
int					philosopers_eats_all(t_philosopher **philosophers);
int					is_dead_flag_on(t_philosopher *p);

// is_dead_mutex.c
int					lock_is_dead_mutex(t_philosopher *p);
int					unlock_is_dead_mutex(t_philosopher *p);

// check_is_dead_and_print.c
int					print_message(t_philosopher *p, char *str);

// get_info_with_mutex.c
size_t				get_first_eating(t_philosopher *p);
size_t				get_time_to_die(t_philosopher *p);
size_t				get_time_to_eat(t_philosopher *p);
size_t				get_time_to_sleep(t_philosopher *p);
int					get_is_dead(t_philosopher *p);

// get_info_with_mutex_long.c
long				get_is_eat_all_num(t_philosopher *p);
long				get_num_of_philo(t_philosopher *p);
long				get_num_of_times_philo_must_eat(t_philosopher *p);
long				get_is_eat_all(t_philosopher *p);

// get_info_with_mutex_philosophers.c
size_t				get_start_eating(t_philosopher *p);
size_t				get_start_sleeping(t_philosopher *p);
long				get_eat_count(t_philosopher *p);

// set_value_safe.c
int					set_value_first_eating(t_philosopher *p);
int					set_value_start_eating(t_philosopher *p);
int					set_value_eat_count(t_philosopher *p);
int					set_value_is_eat_all(t_philosopher *p);

// take_fork_odd_even.c
int					odd_fork(t_philosopher *p, long y);
int					even_fork(t_philosopher *p, long y);

// print_str_error.c
void				print_str_error(char *str);

// utils
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);

#endif