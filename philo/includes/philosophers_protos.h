/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_protos.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:06:57 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 15:26:10 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_PROTOS_H
# define PHILOSOPHERS_PROTOS_H
# include "philosophers_structs.h"
# include "philosophers.h"

/* INIT */
int init(int ac, char **av, t_vars *vars);

/* ATOI DEF */
int	atoi_def(const char *str, unsigned int *val);

/* Tests */
int	test_01(void);
int	test_02(void);
int	test_03(void);
int	test_04(void);
int	test_05(void);
int	test_06(void);
int	test_07(void);

#endif
