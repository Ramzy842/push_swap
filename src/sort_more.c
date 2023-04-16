/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:16:19 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/16 06:06:43 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	extract_index_biggest(t_stack *s, int biggest_num)
{
	int	x;
	int	index;

	x = 0;
	index = 0;
	while (x <= s->top_b)
	{
		if (s->stack_b[x] == biggest_num)
		{
			index = x;
			return (index);
		}
		x++;
	}
	return (index);
}

int	extract_biggest(t_stack *s)
{
	int	x;
	int	biggest_number;

	x = 0;
	biggest_number = *(s->stack_b + s->top_b);
	while (x <= s->top_b)
	{
		if (biggest_number < *(s->stack_b + x))
			biggest_number = *(s->stack_b + x);
		x++;
	}
	return (biggest_number);
}

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
			return (index);
		}
		x++;
	}
	return (index);
}

void	sort_more(t_stack *stacks, int *temp_arr, int length)
{
	int	cte;
	int	range_movement;
	int	x;

	x = 0;
	range_movement = 0;
	if (length <= 100)
		cte = 15;
	else
		cte = 35;

	int *arr = stacks->stack_a;
	int top = stacks->top_a;
	int extracted_num;
	while (stacks->top_a != -1)
	{
		extracted_num = extract_num_index(arr[stacks->top_a], temp_arr, top);
		if (extracted_num <= range_movement)
		{
			pb(stacks);
			rb(stacks);
			range_movement++;
		}
		else if (extracted_num <= (range_movement + cte))
		{
			pb(stacks);
			range_movement++;
		}
		else
			ra(stacks);
	}

	int	biggest_num;
	int	index;
	int	distance;
	while (stacks->top_b != -1)
	{
		biggest_num = extract_biggest(stacks);
		index = extract_index_biggest(stacks, biggest_num);
		distance = (stacks->top_b - index);
		while (stacks->stack_b[stacks->top_b] != biggest_num)
		{
			if (distance >= (index))
				rrb(stacks);
			else
				rb(stacks);
		}
		pa(stacks);
	}
}