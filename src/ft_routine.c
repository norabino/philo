/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:00:02 by norabino          #+#    #+#             */
/*   Updated: 2025/04/16 13:20:40 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *data_philo)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data_philo;
	table = philo->table;
	if (table->how_many_meals == 0)
		return (ft_i_am_replete(philo), NULL);
	while (!ft_check_death(philo))
	{
		ft_think(philo);
		if (ft_eat(philo) == 1)
			break ;
		ft_sleep(philo);
	}
	ft_i_am_replete(philo);
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	if (philo->table->how_many_meals == 1)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_wwrite(philo, LEFT_FORK);
		ft_usleep(philo->table->time_to_die);
		ft_write(philo, DIE);
		pthread_mutex_unlock(&philo->left_fork->fork);
		return (1);
	}
	pthread_mutex_lock()
}