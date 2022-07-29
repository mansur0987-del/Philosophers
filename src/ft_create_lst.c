/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:08:39 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 18:09:40 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_ph	*ft_put_lst(t_ph **phil, int i)
{
	t_ph	*new;
	t_ph	*front;

	new = malloc(sizeof(t_ph));
	if (new == NULL)
		return (NULL);
	new->pref = NULL;
	new->next = NULL;
	new->numb = i;
	new->left = i;
	new->right = i + 1;
	front = (*phil);
	if (front == NULL)
		return (new);
	while (front->next != NULL)
		front = front->next;
	new->pref = front;
	front->next = new;
	return (new);
}

void	ft_last_lst(t_ph **phil, t_argv *av)
{
	t_ph	*last;
	t_ph	*front;

	front = *phil;
	last = *phil;
	while (last->pref != NULL)
	{
		last->die = av->die;
		last->eat = av->eat;
		last->num_eat = av->num_eat;
		last->sleep = av->sleep;
		last->philo = av->philo;
		last = last->pref;
	}
	last->die = av->die;
	last->eat = av->eat;
	last->num_eat = av->num_eat;
	last->sleep = av->sleep;
	last->philo = av->philo;
	front->next = last;
	front->right = last->left;
	last->pref = front;
}

int	ft_create_fork(t_argv *av)
{
	int	i;

	av->forks = NULL;
	av->forks = (pthread_mutex_t *)malloc(sizeof(av->forks) * av->philo);
	if (av->forks == NULL || pthread_mutex_init(&av->write, NULL))
		return (0);
	i = 0;
	while (i < av->philo)
	{
		if (pthread_mutex_init(&(av->forks[i]), NULL))
			return (0);
		i++;
	}
	return (1);
}

int	ft_create_lst(t_argv *av)
{
	int	i;

	i = 0;
	while (i < av->philo)
	{
		av->phil = ft_put_lst(&(av->phil), i++);
		if (av->phil == NULL)
			return (0);
	}
	ft_last_lst(&(av->phil), av);
	if (!(ft_create_fork(av)))
		return (0);
	i = 0;
	while (i++ < av->philo)
	{
		av->phil->write = &av->write;
		av->phil->forks = av->forks;
		av->phil->kill = 0;
		av->phil = av->phil->next;
	}
	return (1);
}
