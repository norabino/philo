/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:26:38 by norabino          #+#    #+#             */
/*   Updated: 2025/04/20 21:37:21 by norabino         ###   ########.fr       */
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
	long	nb;

	if (ac < 5)
		return (printf("Error: Too few arguments.\n"), 0);
	if (ac > 6)
		return (printf("Error: Too much arguments.\n"), 0);
	i = 1;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if ((nb > 2147483647 || nb < 0)
			|| (!nb && !ft_iszero(av[i])))
			return (printf("Argument(s) not valid.\n"), 0);
		i++;
	}
	return (1);
}