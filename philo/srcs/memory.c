/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:20:09 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 17:13:38 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_philos(t_philo **philosophers)
{
	int	i;

	i = 0;
	while (philosophers[i])
	{
		free(philosophers[i]);
		philosophers[i] = NULL;
		i++;
	}
	free(philosophers);
	philosophers = NULL;
}

void	memory_cleaning(t_vars *vars)
{
	if (vars->philosophers)
		free_philos(vars->philosophers);
}
