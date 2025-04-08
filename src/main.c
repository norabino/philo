/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:21:08 by norabino          #+#    #+#             */
/*   Updated: 2025/04/08 16:36:49 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (!ft_parse(ac, av))
		return (printf("Try : ./philo [ nb_philo ] [ die ] [ eat ] [ sleep ] ([ max_meals ])\n"), 1);
	table = ft_init(av);
	if (!table)
		return (1);
	ft_end_simulation(table);
	return (0);
}