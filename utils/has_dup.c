/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:58:38 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/17 09:38:24 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_dup(long long nb, char **av, int *length)
{
	int	x;
	int	number_of_occurences;

	x = 0;
	number_of_occurences = 0;
	while (x < *length)
	{
		if (ft_atoi(av[x]) == nb)
			number_of_occurences++;
		x++;
	}
	if (number_of_occurences > 1)
		return (1);
	return (0);
}
