/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:00:02 by norabino          #+#    #+#             */
/*   Updated: 2025/04/20 22:07:19 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *data_philo)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data_philo;
	table = philo->table;
	if (table->how_many_meals == 0)
		return (ft_i_am_replete(philo), NULL);
	while (!ft_check_death(philo))
	{
		ft_think(philo);
		if (ft_eat(philo) == 1)
			break ;
		ft_sleep(philo);
	}
	ft_i_am_replete(philo);
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	if (philo->table->how_many_meals == 1)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_write(philo, LEFT_FORK);
		ft_usleep(philo->table->time_to_die);
		ft_write(philo, DIE);
		pthread_mutex_unlock(&philo->left_fork->fork);
		return (1);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		ft_write(philo, RIGHT_FORK);
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_write(philo, LEFT_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_write(philo, LEFT_FORK);
		pthread_mutex_lock(&philo->right_fork->fork);
		ft_write(philo, RIGHT_FORK);
	}
	ft_secure_eating(philo);
	return (0);
}

int	ft_secure_eating(t_philo *philo)
{
	ft_write(philo, EAT);
	pthread_mutex_lock(&philo->time);
	philo->last_meal = ft_gettimeofday() - philo->table->start_simulation;
	pthread_mutex_unlock(&philo->time);
	//ft_usleep_max_meals(philo->table->time_to_eat, philo, max_meals, flg);
	//(*max_meals)++;
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return (0);
}


void	ft_sleep(t_philo *philo)
{
	ft_write(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_write(philo, THINK);
}