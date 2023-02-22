/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:17 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 13:45:04 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	aux_atoi_def(const char *str, unsigned long *nb, int i)
{
	while ('0' <= str[i] && str[i] <= '9')
	{
		*nb = *nb * 10 + str[i] - '0';
		if (*nb > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	atoi_def(const char *str, unsigned int *val)
{
	unsigned long	nb;
	int		i;

	nb = 0;
	i = 0;
	while (str[i] == ' ' || (8 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (1);
	else if (str[i] == '+')
		i++;
	if (aux_atoi_def(str, &nb, i))
		return (1);
	*val = nb;
	return (0);
}
