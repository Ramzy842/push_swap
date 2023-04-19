/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:23:21 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/19 09:23:58 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(t_stack *stacks, char **splitted)
{
	int	y;

	y = stacks->length;
	while (y > 0)
	{
		(stacks->top_a)++;
		*(stacks->stack_a + (stacks->top_a)) = ft_atoi(splitted[y - 1]);
		y--;
	}
}

int	*fill_arr(int *arr, char **splitted, int len)
{
	int	x;

	x = 0;
	arr = malloc(len * sizeof(int));
	while (x < len)
	{
		*(arr + x) = ft_atoi(splitted[x]);
		x++;
	}
	return (arr);
}
