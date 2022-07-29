/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:14:02 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 17:57:01 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	usleep_me(int time_to_sleep)
{
	struct timeval	time;
	long long		start_time;

	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	while ((long long)time_to_sleep > \
	((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time))
	{
		gettimeofday(&time, NULL);
		usleep(50);
	}
}

long	ft_start(void)
{
	long long		time_ms;
	struct timeval	tv1;

	gettimeofday(&tv1, 0);
	time_ms = tv1.tv_sec * 1000 + tv1.tv_usec / 1000;
	return (time_ms);
}

int	ft_check_kill(t_ph *phils)
{
	int	i;

	i = 0;
	while (i++ < phils->philo)
	{
		if (phils->kill)
			return (0);
		phils = phils->next;
	}
	return (1);
}
