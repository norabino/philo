/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:21:30 by norabino          #+#    #+#             */
/*   Updated: 2025/07/06 16:11:56 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_monitor(void *data)
{
	int			i;
	t_table		*table;
	t_philo		*philo;

	table = (t_table *)data;
	philo = table->philos;
	while (1)
	{
		if (ft_check_all_philos_full(philo))
			return (NULL);
		i = 0;
		while (i < philo->table->nb_philo)
		{
			if (!ft_check_starvation(&philo[i]))
			{
				ft_philo_died(table, philo[i].id);
				return (NULL);
			}
			i++;
		}
		if (ft_check_all_philos_full(philo))
			return (NULL);
		usleep(50);
	}
	return (NULL);
}

void	ft_philo_died(t_table *table, int id)
{
	pthread_mutex_lock(&table->simulation_state);
	table->finished = 1;
	pthread_mutex_unlock(&table->simulation_state);
	pthread_mutex_lock(&table->write);
	printf("%ld %d died\n",
		gettimeofday_ms() - table->time_start,
		id);
	pthread_mutex_unlock(&table->write);
}
