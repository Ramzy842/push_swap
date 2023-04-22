/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:17:00 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/22 05:26:12 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *stacks)
{
	swap(&((stacks->stack_b)[stacks->top_b]),
		&((stacks->stack_b)[stacks->top_b - 1]));
	write(1, "sb\n", 3);
}

void	pb(t_stack *stacks)
{
	stacks->top_b += 1;
	*(stacks->stack_b + stacks->top_b) = *(stacks->stack_a + stacks->top_a);
	stacks->top_a -= 1;
	write(1, "pb\n", 3);
}

void	rb(t_stack *stacks)
{
	int	temp;
	int	x;

	x = stacks->top_b;
	temp = *(stacks->stack_b + (stacks->top_b));
	while (x > 0)
	{
		*(stacks->stack_b + x) = *(stacks->stack_b + (x - 1));
		x--;
	}
	*(stacks->stack_b + 0) = temp;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stacks)
{
	int	temp;
	int	x;
	int	y;

	x = 0;
	y = 1;
	temp = *(stacks->stack_b + 0);
	while (x < stacks->top_b)
	{
		*(stacks->stack_b + x) = *(stacks->stack_b
				+ (stacks->top_b - (stacks->top_b - y)));
		x++;
		y++;
	}
	*(stacks->stack_b + stacks->top_b) = temp;
	write(1, "rrb\n", 4);
}
