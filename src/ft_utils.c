/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:20:16 by norabino          #+#    #+#             */
/*   Updated: 2025/07/06 12:50:15 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_write(t_philo *philo, t_actions action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->write);
	timestamp = gettimeofday_ms() - philo->table->time_start;
	if (ft_simulation_active(philo->table))
	{
		if (action == L_FORK)
			printf("%ld %d has taken a fork\n", timestamp, philo->id);
		else if (action == R_FORK)
			printf("%ld %d has taken a fork\n", timestamp, philo->id);
		else if (action == EAT)
			printf("%ld %d is eating\n", timestamp, philo->id);
		else if (action == SLEEP)
			printf("%ld %d is sleeping\n", timestamp, philo->id);
		else if (action == THINK)
			printf("%ld %d is thinking\n", timestamp, philo->id);
		else if (action == DIE)
			printf("%ld %d died\n", timestamp, philo->id);
	}
	pthread_mutex_unlock(&philo->table->write);
}

void	ft_take_L_Fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	ft_write(philo, L_FORK);
}

void	ft_take_R_Fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	ft_write(philo, R_FORK);
}
