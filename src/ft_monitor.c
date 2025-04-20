/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:21:30 by norabino          #+#    #+#             */
/*   Updated: 2025/04/20 21:32:03 by norabino         ###   ########.fr       */
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
		i = 0;
		while (i < philo->table->nb_philo)
		{
			if (ft_check_last_meal(&philo[i]))
			{
				ft_philo_died(table, philo[i].id);
				return (NULL);
			}
			i++;
		}
		if (table->how_many_meals != -1)
		{
			if (ft_check_replete(philo) == 1)
				return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}