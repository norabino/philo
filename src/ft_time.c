/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:09:50 by norabino          #+#    #+#             */
/*   Updated: 2025/07/12 02:37:20 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	gettimeofday_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(long ms, t_table *table)
{
	long		start_time;

	start_time = gettimeofday_ms();
	while (gettimeofday_ms() - start_time < ms)
	{
		pthread_mutex_lock(&table->simulation_state);
		if (table->finished)
		{
			pthread_mutex_unlock(&table->simulation_state);
			break ;
		}
		pthread_mutex_unlock(&table->simulation_state);
		usleep(50);
	}
}
