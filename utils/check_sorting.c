/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:18:25 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/19 09:18:55 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sort_temp_array(int *stack, int length)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < length - 1)
	{
		while (y < length - x - 1)
		{
			if (stack[y] > stack[y + 1])
				swap(&stack[y], &stack[y + 1]);
			y++;
		}
		x++;
		y = 0;
	}
	return (stack);
}

int	is_sorted(int *arr, int length)
{
	int	x;

	x = 0;
	while (x < length - 1)
	{
		if (arr[x] < arr[x + 1])
			return (0);
		x++;
	}
	return (1);
}
