/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:10:27 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 18:18:31 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static t_philo	*new_philo(int nb, t_vars *vars)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	thread = 0;
	philo->thread = thread;
	philo->nb = nb;
	philo->ttl = vars->ttd;
	philo->forks = 1;
	return (philo);
}

int	create_philos(t_vars *vars)
{
	unsigned int	i;

	i = 0;
	vars->philosophers = malloc(sizeof(t_philo *) * (vars->nb_philo + 1));
	if (!vars->philosophers)
		return (1);
	(vars->philosophers)[vars->nb_philo] = NULL;
	while (i < vars->nb_philo)
	{
		(vars->philosophers)[i] = new_philo(i + 1, vars);
		if (!((vars->philosophers)[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init(int ac, char **av, t_vars *vars)
{
	struct timeval	tv;

	if (ac < 5 || ac > 6)
		return (1);
	if (atoi_def(av[1], &(vars->nb_philo)))
		return (1);
	else if (atoi_def(av[2], &(vars->ttd)))
		return (1);
	else if (atoi_def(av[3], &(vars->tte)))
		return (1);
	else if (atoi_def(av[4], &(vars->tts)))
		return (1);
	if (ac == 6)
	{
		if (atoi_def(av[5], &(vars->ttf)))
			return (1);
	}
	if (create_philos(vars))
		return (1);
	if (gettimeofday(&tv, NULL))
		return (1);
	vars->start_time = tv.tv_usec;
	return (0);
}
