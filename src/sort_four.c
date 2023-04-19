/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:11:17 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/19 06:54:22 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// function to return index of smallest number
// while stack[top] != smallest number
	// calculate how far it is from top value
	//distance = top - index of smallest number
	// if distance == index of smallest number => pb
	// if distance > index of smallest number => rra
	// if distance < index of smallest number => ra

int	extract_index_smallest(t_stack *s)
{
	int	x;
	int	index;
	int	smallest_num;

	x = 0;
	index = 0;
	smallest_num = *(s->stack_a + 0);
	while (x <= s->top_a)
	{
		if (smallest_num > *(s->stack_a + x))
		{
			smallest_num = *(s->stack_a + x);
			index = x;
		}
		x++;
	}
	return (index);
}

int	extract_smallest(t_stack *s)
{
	int	x;
	int	smallest_num;

	x = 0;
	smallest_num = *(s->stack_a + 0);
	while (x <= s->top_a)
	{
		if (smallest_num > *(s->stack_a + x))
			smallest_num = *(s->stack_a + x);
		x++;
	}
	return (smallest_num);
}

void	sort_four(t_stack *stacks)
{
	int	index;
	int	smallest_num;
	int	distance;

	index = extract_index_smallest(stacks);
	smallest_num = extract_smallest(stacks);
	distance = stacks->top_a - index;
	while (stacks->stack_a[stacks->top_a] != smallest_num)
	{
		if (distance > index)
			rra(stacks);
		else if (distance < index)
			ra(stacks);
	}
	if (is_sorted(stacks->stack_a, stacks->length))
		return ;
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}
