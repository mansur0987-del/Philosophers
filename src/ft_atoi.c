/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:02:14 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/06 15:06:42 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	unsigned long long	out;
	long long			i;
	long long			g;

	i = 0;
	out = 0;
	while (str[i] && ((str[i] > 9 && str[i] < 13) || str[i] == 32))
		i++;
	g = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
		out = out * 10 + (str[i++] - '0');
	if (str[g] == '-' && out > 9223372036854775807)
		return (0);
	else if (str[g] != '-' && out > 9223372036854775806)
		return (-1);
	if (str[g] == '-')
		return (-out);
	return (out);
}
