/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:54:24 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/19 09:15:36 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	extract_num_index(int value, int *temp_arr, int top)
{
	int	x;
	int	index;

	x = 0;
	index = 0;
	while (x <= top)
	{
		if (temp_arr[x] == value)
		{
			index = x;
			break ;
		}
		x++;
	}
	return (index);
}

void	extract_biggest(t_stack *s, int *number, int *index)
{
	int	x;

	x = 0;
	*number = *(s->stack_b + s->top_b);
	*index = s->top_b;
	while (x <= s->top_b)
	{
		if (*(number) < *(s->stack_b + x))
		{
			*(number) = *(s->stack_b + x);
			*(index) = x;
		}
		x++;
	}
}
