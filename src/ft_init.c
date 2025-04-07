/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:14:02 by norabino          #+#    #+#             */
/*   Updated: 2025/04/03 14:55:14 by norabino         ###   ########.fr       */
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
}

int	ft_init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 1;
	if (table->nb_philo != 0)
		philo = malloc(sizeof(t_philo));
	while (i < table->nb_philo)
	{
		if (!philo)
			return (0);
		philo->table = table;
		i++;
		if (i < table->nb_philo - 1)
		{
			philo->next = malloc(sizeof(t_philo));
			philo = philo->next;
		}
	}
	return (1);
}

int	ft_init(char **av)
{
	t_table	table;

	ft_init_table(&table, av);
	if (!ft_init_philos(&table))
		return (printf("error malloc philo"), 1);
	printf("nbphilo = %d\ntime to die = %d\ntime to eat = %d\ntime to sleep = %d\nhowmanyeat = %d", table.nb_philo, table.time_to_die, table.time_to_eat, table.time_to_sleep, table.how_many_eat);
	return (0);
}
