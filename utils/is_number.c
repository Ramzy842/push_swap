/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:17:07 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/10 13:20:38 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *arg)
{
	int	x;

	x = 0;
	if ((arg[x] == '-' && arg[x + 1] == '+')
		|| (arg[x] == '+' && arg[x + 1] == '-')
		|| (arg[x] == '-' && arg[x + 1] == '-')
		|| (arg[x] == '+' && arg[x + 1] == '+'))
		return (0);
	while (arg[x] != '\0')
	{
		if ((arg[x] == '-' || arg[x] == '+') && !ft_isdigit(arg[x + 1]))
			return (0);
		if ((arg[x] == '-' || arg[x] == '+'))
		{
			x++;
			continue ;
		}
		if (!ft_isdigit(arg[x]))
			return (0);
		x++;
	}
	return (1);
}
