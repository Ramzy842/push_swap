/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:16:16 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/14 00:02:07 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stack *stacks)
{
	int	index;
	int	smallest_num;
	int	distance;

	index = extract_index_smallest(stacks);
	smallest_num = extract_smallest(stacks);
	distance = stacks->top_a - index;
	while (stacks->stack_a[stacks->top_a] != smallest_num)
	{
		if (distance >= index)
			rra(stacks);
		else if (distance < index)
			ra(stacks);
	}
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}
