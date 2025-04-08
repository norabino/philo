/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:14:02 by norabino          #+#    #+#             */
/*   Updated: 2025/04/08 16:38:55 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_table(t_table *table, char **av)
{
	table->nb_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		table->how_many_eat = ft_atol(av[5]);
	else
		table->how_many_eat = -1;
	pthread_create(&table->monitor, NULL, ft_monitor, table);
	table->philos = malloc(table->nb_philo * sizeof(t_philo));
	table->forks = malloc(table->nb_philo * sizeof(t_fork));
}

int	ft_init_forks(t_table *table)
{
	int 	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->forks[i].id = i + 1;
		pthread_mutex_init(&table->forks[i].fork, NULL);
		i++;
	}
	return (1);
}

int	ft_init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->left_fork = &table->forks[i];
		if (i == table->nb_philo - 1)
            philo->right_fork = &table->forks[0];
        else
            philo->right_fork = &table->forks[i + 1];
		philo->table = table;
		pthread_create(&philo->id_thread, NULL, ft_routine, philo);
		i++;
	}
	return (1);
}

t_table	*ft_init(char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (table);
	ft_init_table(table, av);
	if (!ft_init_forks(table) || !ft_init_philos(table))
		return (printf("error malloc philo ou fork"), NULL);
	printf("nbphilo = %d\ntime to die = %d\ntime to eat = %d\ntime to sleep = %d\nhowmanyeat = %d\n", table->nb_philo, table->time_to_die, table->time_to_eat, table->time_to_sleep, table->how_many_eat);
	return (table);
}
