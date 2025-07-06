/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:00:02 by norabino          #+#    #+#             */
/*   Updated: 2025/07/06 16:36:03 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *data_philo)
{
	t_philo	*philo;
	t_table	*table;
	int		meals_count;

	meals_count = 0;
	philo = (t_philo *)data_philo;
	table = philo->table;
	if (table->how_many_meals == 0)
		return (ft_all_meals_taken(philo), NULL);
	while (ft_simulation_active(philo->table))
	{
		ft_think(philo);
		if (!ft_eat(philo, &meals_count) || philo->finished_eating)
			break ;
		ft_sleep(philo);
	}
	return (NULL);
}

/*int	ft_eat(t_philo *philo, int *meals_count)
{
	if (philo->table->nb_philo == 1)
	{
		ft_take_L_Fork(philo);
		ft_usleep(philo->table->time_to_die);
		ft_write(philo, DIE);
		pthread_mutex_unlock(&philo->left_fork->fork);
		return (0);
	}
	if (philo->id % 2 == 0)
	{
		ft_take_R_Fork(philo);
		ft_take_L_Fork(philo);
	}
	else
	{
		ft_take_L_Fork(philo);
		ft_take_R_Fork(philo);
	}
	ft_write(philo, EAT);
	return (ft_secure_eating(philo, meals_count));
}*/

int	ft_eat(t_philo *philo, int *meals_count)
{
    if (philo->table->nb_philo == 1)
    {
        ft_take_L_Fork(philo);
        ft_usleep(philo->table->time_to_die);
        ft_write(philo, DIE);
        pthread_mutex_unlock(&philo->left_fork->fork);
        return (0);
    }
    if (philo->id % 2 == 0)
    {
        ft_take_R_Fork(philo);
        if (!ft_simulation_active(philo->table))
        {
            pthread_mutex_unlock(&philo->right_fork->fork);
            return (0);
        }
        ft_take_L_Fork(philo);
    }
    else
    {
        ft_take_L_Fork(philo);
        if (!ft_simulation_active(philo->table))
        {
            pthread_mutex_unlock(&philo->left_fork->fork);
            return (0);
        }
        ft_take_R_Fork(philo);
    }
    
    if (!ft_simulation_active(philo->table))
    {
        pthread_mutex_unlock(&philo->right_fork->fork);
        pthread_mutex_unlock(&philo->left_fork->fork);
        return (0);
    }
    
    ft_write(philo, EAT);
    return (ft_secure_eating(philo, meals_count));
}

int	ft_secure_eating(t_philo *philo, int *meals_count)
{
	pthread_mutex_lock(&philo->time);
	philo->last_meal = gettimeofday_ms() - philo->table->time_start;
	pthread_mutex_unlock(&philo->time);
	ft_usleep(philo->table->time_to_eat);
	(*meals_count)++;
	if (philo->table->how_many_meals > 0 && *meals_count >= philo->table->how_many_meals)
	{
		philo->finished_eating = 1;
		ft_all_meals_taken(philo);
	}
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return (1);
}


void	ft_sleep(t_philo *philo)
{
	ft_write(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_write(philo, THINK);
}