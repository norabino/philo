/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:51:19 by norabino          #+#    #+#             */
/*   Updated: 2025/04/07 21:15:35 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <pthread.h>

# include <sys/time.h>

typedef struct s_table
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			how_many_eat;
	t_philo		*philos;
	t_forks		*forks;
	pthread_t	monitor;
}	t_table;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int					id;
	pthread_t			id_thread;
	pthread_mutex_t		time;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_table				*table;
}	t_philo;


int	ft_init(char **av);

int	ft_atoi(const char *nptr);

#endif