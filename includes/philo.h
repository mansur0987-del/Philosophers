/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:32:34 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/20 17:56:41 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_ph
{
	int				numb;
	int				die;
	int				kill;
	int				eat;
	int				sleep;
	int				num_eat;
	int				philo;
	int				left;
	int				right;
	long long		time_st;
	long long		time_st_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write;
	pthread_t		threads;
	struct s_ph		*next;
	struct s_ph		*pref;
}					t_ph;

typedef struct s_argv
{
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				num_eat;
	t_ph			*phil;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_argv;

size_t	ft_putstr_len(int fd, char	*str);
void	ft_putnbr_fd(long n, int fd);
int		ft_atoi(const char *str);
int		ft_check_argv(int argc, char **argv, t_argv *av);
int		ft_clear_av(t_argv *av);
int		ft_create_lst(t_argv *av);
int		ft_go(t_argv *av);
void	ft_printf(t_ph *phil, char *msg);
void	ft_printf_die(t_ph *phil, char *msg);
long	ft_start(void);
void	usleep_me(int time_to_sleep);
int		ft_check_kill(t_ph *phils);

#endif
