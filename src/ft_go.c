/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:59:23 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 17:52:24 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_life(t_ph *phils, int check)
{
	if (check == 3 && (long long)phils->die < \
	ft_start() - phils->time_st_eat + phils->eat)
	{
		usleep_me(phils->die - (ft_start() - phils->time_st_eat));
		phils->kill = 1;
		ft_printf_die(phils, "died\n");
		return (0);
	}
	else if ((long long)phils->die < ft_start() - phils->time_st_eat)
	{
		phils->kill = 1;
		ft_printf_die(phils, "died\n");
		return (0);
	}
	return (1);
}

int	ft_check_num_eat(t_ph *phils, int check)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k++ < phils->philo)
	{
		if (!(phils->num_eat))
			i++;
		if (phils->kill)
		{
			i = phils->philo;
			break ;
		}
		phils = phils->next;
	}
	if (i == phils->philo || !(ft_life(phils, check)))
	{
		pthread_mutex_unlock(&(phils->forks[phils->right]));
		pthread_mutex_unlock(&(phils->forks[phils->left]));
		return (0);
	}
	return (1);
}

int	ft_eat(t_ph *phils)
{
	pthread_mutex_lock(&(phils->forks[phils->left]));
	ft_printf(phils, "has taken a fork\n");
	pthread_mutex_lock(&(phils->forks[phils->right]));
	ft_printf(phils, "has taken a fork\n");
	ft_printf(phils, "is eating\n");
	if (!(ft_check_num_eat(phils, 3)))
		return (0);
	usleep_me(phils->eat);
	if (phils->num_eat > 0)
		phils->num_eat--;
	phils->time_st_eat = ft_start();
	ft_printf(((t_ph *)phils), "is sleeping\n");
	pthread_mutex_unlock(&(phils->forks[phils->right]));
	pthread_mutex_unlock(&(phils->forks[phils->left]));
	return (1);
}

void	*ft_simul(void *phils)
{
	if (((t_ph *)phils)->numb % 2)
		usleep_me(100);
	while (ft_check_num_eat((t_ph *)phils, 2))
	{
		if (!(ft_eat(((t_ph *)phils))))
			return (NULL);
		if (!(ft_check_num_eat(phils, 2)))
			return (NULL);
		usleep_me(((t_ph *)phils)->sleep);
		if (!(ft_check_num_eat(phils, 2)))
			return (NULL);
		ft_printf(((t_ph *)phils), "is thinking\n");
	}
	return (NULL);
}

int	ft_go(t_argv *av)
{
	int	i;

	i = 0;
	while (i < av->philo)
	{
		av->phil->time_st = ft_start();
		av->phil->time_st_eat = ft_start();
		if (pthread_create(&(av->phil->threads), NULL, ft_simul, av->phil))
			return (0);
		i++;
		av->phil = av->phil->next;
	}
	i = 0;
	while (i < av->philo)
	{
		if (pthread_join(av->phil->threads, NULL))
			return (0);
		i++;
	}
	return (1);
}
