/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:21:08 by norabino          #+#    #+#             */
/*   Updated: 2025/07/06 16:27:02 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_end_simulation(t_table *table)
{
	int	i;

	pthread_join(table->monitor, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(table->philos[i].id_thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		pthread_mutex_destroy(&table->philos[i].time);
		i++;
	}
	pthread_mutex_destroy(&table->simulation_state);
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->replete);
	free(table->philos);
	free(table->forks);
	free(table);
}

int	main(int ac, char **av)
{
	t_table *table;

	if (!ft_parse(ac, av))
		return (printf("Try : ./philo [ nb_philo ] [ die ] [ eat ] [ sleep ] ([ max_meals ])\n"), 1);
	table = ft_init(av);
	if (!table)
		return (1);
	ft_end_simulation(table);
	return (0);
}