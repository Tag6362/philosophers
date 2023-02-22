/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:47:08 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 17:48:32 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	test_01();
	test_02();
	test_03();
	test_04();
	return (EXIT_SUCCESS);
}
/*
	t_vars	vars;

	if (init(ac, av, &vars))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
*/
