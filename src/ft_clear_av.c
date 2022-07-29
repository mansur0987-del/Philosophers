/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:09:29 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 18:08:57 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_clear_av(t_argv *av)
{
	int		i;
	t_ph	*tmp;

	i = 0;
	pthread_mutex_destroy(&(av->write));
	while (av->phil != NULL && i < av->philo)
	{
		if (av->forks != NULL)
			pthread_mutex_destroy(&(av->forks[i++]));
		tmp = av->phil->next;
		free (av->phil);
		av->phil = tmp;
	}
	free(av->forks);
	if (av != NULL)
		free(av);
	av = NULL;
	return (0);
}
