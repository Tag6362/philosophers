/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_protos.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:06:57 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 17:46:44 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_PROTOS_H
# define PHILOSOPHERS_PROTOS_H
# include "philosophers_structs.h"
# include "philosophers.h"

/* INIT */
int		init(int ac, char **av, t_vars *vars);

/* ATOI DEF */
int		atoi_def(const char *str, unsigned int *val);

/* TIME */
int		print_action(t_philo *philo, int action, t_vars *vars);

/* MEMORY */
void	memory_cleaning(t_vars *vars);

/* Tests */
int	test_01(void);
int	test_02(void);
int	test_03(void);
int	test_04(void);
int	test_05(void);
int	test_06(void);
int	test_07(void);

#endif
