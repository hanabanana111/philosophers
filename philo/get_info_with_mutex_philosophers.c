/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_with_mutex_philosophers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:19:13 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/23 12:19:32 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

size_t	get_start_eating(t_philosopher *p)
{
	size_t	ret;

	pthread_mutex_lock(&p->start_eating_mutex);
	ret = p->start_eating;
	pthread_mutex_unlock(&p->start_eating_mutex);
	return (ret);
}

size_t	get_start_sleeping(t_philosopher *p)
{
	size_t	ret;

	pthread_mutex_lock(&p->start_sleeping_mutex);
	ret = p->start_sleeping;
	pthread_mutex_unlock(&p->start_sleeping_mutex);
	return (ret);
}

long	get_eat_count(t_philosopher *p)
{
	long	ret;

	if (pthread_mutex_lock(&p->eat_count_mutex))
	ret = p->eat_count;
	if (pthread_mutex_unlock(&p->eat_count_mutex))
	return (ret);
}
