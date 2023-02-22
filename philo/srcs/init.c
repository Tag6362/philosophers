/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:10:27 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 15:36:01 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init(int ac, char **av, t_vars *vars)
{
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
	return (0);
}

int create_philo(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_philo)
	{
		
		i++;
	}
}
