/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:20:16 by norabino          #+#    #+#             */
/*   Updated: 2025/04/20 21:59:38 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->info);
	if (philo->table->simulation_ended == 1)
	{
		pthread_mutex_unlock(&philo->table->info);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->info);
	return (0);
}

void ft_write(t_philo *philo, t_actions action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->write);
	timestamp = ft_gettimeofday() - philo->table->start_simulation;
	if (!ft_check_death(philo))
	{
		if (action == LEFT_FORK)
			printf("%ld %d has taken a fork\n", timestamp, philo->id);
		else if (action == RIGHT_FORK)
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

long	ft_get_current_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(long ms)
{
	long		start_time;

	start_time = ft_get_current_timestamp();
	while (ft_get_current_timestamp() - start_time < ms)
		usleep(50);
}
