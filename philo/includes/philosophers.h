/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:47:11 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 18:09:31 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "philosophers_protos.h"
# include "philosophers_structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

enum e_actions
{
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
};
#endif
