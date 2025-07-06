/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:20 by norabino          #+#    #+#             */
/*   Updated: 2025/07/06 12:10:54 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_simulation_active(t_table *table)
{
	pthread_mutex_lock(&table->simulation_state);
	if (table->finished)
	{
		pthread_mutex_unlock(&table->simulation_state);
		return (0);
	}
	pthread_mutex_unlock(&table->simulation_state);
	return (1);
}

int	ft_check_starvation(t_philo *philo)
{
	pthread_mutex_lock(&philo->time);
	if (gettimeofday_ms() - philo->table->time_start
		- philo->last_meal > philo->table->time_to_die)
		return (pthread_mutex_unlock(&philo->time), 0);
	return (pthread_mutex_unlock(&philo->time), 1);
}

int	ft_check_all_philos_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->replete);
	if (philo->table->philos_full == philo->table->nb_philo)
	{
		pthread_mutex_lock(&philo->table->simulation_state);
		philo->table->finished = 1;
		pthread_mutex_unlock(&philo->table->simulation_state);
		pthread_mutex_unlock(&philo->table->replete);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->replete);
	return (0);
}

void	ft_all_meals_taken(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->replete);
	philo->table->philos_full += 1;
	pthread_mutex_unlock(&philo->table->replete);
}
