/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:20 by norabino          #+#    #+#             */
/*   Updated: 2025/04/08 16:18:43 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_end_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(table->philos[i].id_thread, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		pthread_mutex_destroy(&table->philos[i].time);
		i++;
	}
	//pthread_mutex_destroy(&table->info);
	//pthread_mutex_destroy(&table->write);
	//pthread_mutex_destroy(&table->replete);
	free(table->philos);
	free(table->forks);
	free(table);
}