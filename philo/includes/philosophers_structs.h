/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:07:11 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 15:47:53 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_STRUCTS_H
# define PHILOSOPHERS_STRUCTS_H
# include "philosophers_protos.h"
# include "philosophers.h"

typedef struct		s_philo
{
	pthread_t		thread;
	unsigned int	nb;
	unsigned int	ttl;
	unsigned int	has_fork;
}					t_philo;

typedef struct		s_vars	{
	unsigned int	nb_philo;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	ttf;
	t_philo			*philosophers;
}					t_vars;

#endif
