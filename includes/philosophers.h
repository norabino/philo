/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:51:19 by norabino          #+#    #+#             */
/*   Updated: 2025/04/03 14:53:53 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_table
{
	int		nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	how_many_eat;
}	t_table;

typedef struct s_philo
{
	t_table	*table;
	struct s_philo *next;
}	t_philo;

typedef struct s_fork
{
	int	id;
}	t_fork;


int	ft_init(char **av);

int	ft_atoi(const char *nptr);

#endif