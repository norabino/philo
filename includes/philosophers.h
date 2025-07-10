/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:51:19 by norabino          #+#    #+#             */
/*   Updated: 2025/07/10 15:46:25 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <pthread.h>

# include <sys/time.h>

typedef struct s_table	t_table;

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
	long				last_meal;
	int					finished_eating;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				how_many_meals;
	int				philos_full;
	int				finished;
	long			time_start;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		monitor;
	pthread_mutex_t	simulation_state;
	pthread_mutex_t	write;
	pthread_mutex_t	replete;
}	t_table;

typedef enum e_actions
{
	L_FORK,
	R_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_actions;

// FUNCTIONS : 

// Init / Parse
t_table	*ft_init(char **av);
int		ft_parse(int ac, char **av);

// Philos' routine
void	*ft_routine(void *data_philo);
void	ft_think(t_philo *philo);
int		ft_eat(t_philo *philo, int *meals_count);
int		ft_secure_eating(t_philo *philo, int *meals_count);
void	ft_sleep(t_philo *philo);

// Monitor
void	*ft_monitor(void	*data);
void	ft_all_meals_taken(t_philo *philo);
int		ft_check_starvation(t_philo *philo);
int		ft_check_all_philos_full(t_philo *philo);
void	ft_philo_died(t_table *table, int id);
void	ft_end_simulation(t_table *table);
int		ft_simulation_active(t_table *table);

// Utils
void	ft_write(t_philo *philo, t_actions action);
void	ft_take_left_fork(t_philo *philo);
void	ft_take_right_fork(t_philo *philo);

// Atol
long	ft_atol(char *str);
int		ft_isdigit(char c);

// Time
long	gettimeofday_ms(void);
void	ft_usleep(long ms, t_table *table);

#endif