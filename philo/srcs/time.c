/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:34:09 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 18:24:36 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int print_action(t_philo *philo, int action, t_vars *vars)
{
	struct timeval		tv;
	unsigned long long	time;

	if (gettimeofday(&tv, NULL))
		return (1);
	time = tv.tv_usec - vars->start_time;
	if (action == TAKEN_FORK)
		printf("[%llu] %d has taken a fork\n", time, philo->nb);
	else if (action == EATING)
		printf("[%llu] %d is eating\n", time, philo->nb);
	else if (action == SLEEPING)
		printf("[%llu] %d is eating\n", time, philo->nb);
	else if (action == THINKING)
		printf("[%llu] %d is eating\n", time, philo->nb);
	else if (action == DIED)
		printf("[%llu] %d is eating\n", time, philo->nb);
	return (0);
}


