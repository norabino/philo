/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:14:02 by norabino          #+#    #+#             */
/*   Updated: 2025/04/07 22:01:48 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_table(t_table *table, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->how_many_eat = ft_atoi(av[5]);
	else
		table->how_many_eat = -1;
	pthread_create(&table->monitor, NULL, ft_monitor, table);
	table->philos = malloc(table->nb_philo * sizeof(t_philo));
	table->forks = malloc(table->nb_philo * sizeof(t_fork));
}

int	ft_init_forks(t_table *table)
{
	int 	i;
	t_fork	fork;

	i = 0;
	while (i <= table->nb_philo)
	{
		fork.id = i;
		table->forks[i] = fork;
		pthread_mutex_init(&table->forks[i].fork, NULL);
		i++;
	}
}

int	ft_init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_create(&philo->id_thread, NULL, ft_routine, philo);
		philo->id = i;
		philo->left_fork = &table->forks[i];
		philo->right_fork = &table->forks[i + 1];
		philo->table = table;
		philo = &table->philos[i];
		i++;
	}
	return (1);
}

int	ft_init(char **av)
{
	t_table	table;

	ft_init_table(&table, av);
	if (!ft_init_forks(&table) || !ft_init_philos(&table))
		return (printf("error malloc philo"), 1);
	printf("nbphilo = %d\ntime to die = %d\ntime to eat = %d\ntime to sleep = %d\nhowmanyeat = %d", table.nb_philo, table.time_to_die, table.time_to_eat, table.time_to_sleep, table.how_many_eat);
	return (0);
}
