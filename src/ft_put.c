/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:52:32 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 17:56:25 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static size_t	ft_putchar_len(int fd, char c)
{
	write (fd, &c, 1);
	return (1);
}

size_t	ft_putstr_len(int fd, char	*str)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	if (!tmp || tmp == NULL)
	{
		i += ft_putstr_len(fd, "(null)");
		return (i);
	}
	while (tmp[i] != '\0')
	{
		ft_putchar_len(fd, tmp[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (!fd)
		return ;
	if (n < 0)
	{
		n = -n;
		ft_putchar_len(fd, '-');
	}
	if (n >= 10)
		ft_putnbr_fd (n / 10, fd);
	ft_putchar_len(fd, n % 10 + '0');
}

void	ft_printf(t_ph *phil, char *msg)
{
	pthread_mutex_lock(phil->write);
	if (ft_check_kill(phil))
		printf("%lld %d %s", ft_start() - phil->time_st, \
		phil->numb + 1, msg);
	pthread_mutex_unlock(phil->write);
}

void	ft_printf_die(t_ph *phil, char *msg)
{
	static int	i;

	pthread_mutex_lock(phil->write);
	if (!i)
	{
		printf("%lld %d %s", ft_start() - phil->time_st, \
		phil->numb + 1, msg);
		i = 1;
	}
	pthread_mutex_unlock(phil->write);
}
