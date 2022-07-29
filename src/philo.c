/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:31:31 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 16:38:26 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_argv	*av;

	if (argc < 5 || argc > 6)
		return (0);
	av = malloc(sizeof(t_argv));
	if (av == NULL)
		return (0);
	if (!(ft_check_argv(argc, argv, av)))
		return (ft_clear_av(av));
	if (!(ft_create_lst(av)))
		return (ft_clear_av(av));
	if (!(ft_go(av)))
		return (ft_clear_av(av));
	ft_clear_av(av);
	return (1);
}
