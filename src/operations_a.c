/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:41:52 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/22 05:26:08 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stacks)
{
	swap(&((stacks->stack_a)[stacks->top_a]),
		&((stacks->stack_a)[stacks->top_a - 1]));
	write(1, "sa\n", 3);
}

void	pa(t_stack *stacks)
{
	stacks->top_a += 1;
	*(stacks->stack_a + stacks->top_a) = *(stacks->stack_b + stacks->top_b);
	stacks->top_b -= 1;
	write(1, "pa\n", 3);
}

void	ra(t_stack *stacks)
{
	int	temp;
	int	x;

	x = stacks->top_a;
	temp = *(stacks->stack_a + (stacks->top_a));
	while (x > 0)
	{
		*(stacks->stack_a + x) = *(stacks->stack_a + (x - 1));
		x--;
	}
	*(stacks->stack_a + 0) = temp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *stacks)
{
	int	temp;
	int	x;
	int	y;

	x = 0;
	y = 1;
	temp = *(stacks->stack_a + 0);
	while (x <= stacks->top_a)
	{
		*(stacks->stack_a + x) = *(stacks->stack_a
				+ (stacks->top_a - (stacks->top_a - y)));
		x++;
		y++;
	}
	*(stacks->stack_a + stacks->top_a) = temp;
	write(1, "rra\n", 4);
}
