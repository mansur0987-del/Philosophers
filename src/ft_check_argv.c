/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:38:08 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 16:40:29 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_ar(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

static int	ft_chech_philo(t_argv *av)
{
	if (av->philo < 1)
		return (0);
	if (av->philo > 1)
		return (1);
	ft_putstr_len(1, "0 1 has taken a fork\n");
	usleep_me(av->die);
	ft_putnbr_fd(av->die, 1);
	ft_putstr_len(1, " 1 died\n");
	return (0);
}

int	ft_check_argv(int argc, char **argv, t_argv *av)
{
	av->num_eat = -1;
	av->phil = NULL;
	while (argc > 1)
	{
		if (!(ft_check_ar(argv[argc - 1])))
			return (0);
		if (argc == 6)
			av->num_eat = ft_atoi(argv[argc - 1]);
		if (argc == 5)
			av->sleep = ft_atoi(argv[argc - 1]);
		if (argc == 4)
			av->eat = ft_atoi(argv[argc - 1]);
		if (argc == 3)
			av->die = (long)ft_atoi(argv[argc - 1]);
		if (argc == 2)
			av->philo = ft_atoi(argv[argc - 1]);
		argc--;
	}
	if (!(ft_chech_philo(av)))
		return (0);
	return (1);
}
