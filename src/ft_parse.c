/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:26:38 by norabino          #+#    #+#             */
/*   Updated: 2025/07/10 15:49:36 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_iszero(char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (1);
	return (0);
}

int	ft_parse(int ac, char **av)
{
	int		i;
	int		j;
	long	nb;

	if (ac < 5)
		return (write(2, "Error: Too few arguments.\n", 26), 0);
	if (ac > 6)
		return (write(2, "Error: Too much arguments.\n", 27), 0);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (write(2, "Argument(s) not valid.\n", 23), 0);
		nb = ft_atol(av[i]);
		if ((nb > 2147483647 || nb < 0)
			|| (!nb && ft_iszero(av[i])))
		{
			write(2, "Numbers should be between 1 and INT_MAX.\n", 41);
			return (0);
		}
		i++;
	}
	return (1);
}
