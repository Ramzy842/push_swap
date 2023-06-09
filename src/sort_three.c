/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:16:13 by rchahban          #+#    #+#             */
/*   Updated: 2023/05/10 22:56:06 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_one_two(t_stack *stacks)
{
	if ((*(stacks->stack_a + (stacks->top_a))
			> *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1))
			< *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2))
			> *(stacks->stack_a + ((stacks->top_a)))))
		sa(stacks);
	else if ((*(stacks->stack_a + (stacks->top_a))
			> *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1))
			> *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2))
			< *(stacks->stack_a + ((stacks->top_a)))))
	{
		sa(stacks);
		rra(stacks);
	}
}

void	case_three_four(t_stack *stacks)
{
	if ((*(stacks->stack_a + (stacks->top_a))
			> *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1))
			< *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2))
			< *(stacks->stack_a + ((stacks->top_a)))))
		ra(stacks);
	else if ((*(stacks->stack_a + (stacks->top_a))
			< *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1))
			> *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2))
			> *(stacks->stack_a + ((stacks->top_a)))))
	{
		sa(stacks);
		ra(stacks);
	}
}

void	sort_three(t_stack *stacks)
{
	case_one_two(stacks);
	case_three_four(stacks);
}
