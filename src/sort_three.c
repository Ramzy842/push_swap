/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:16:13 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/12 21:12:32 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stacks)
{
	if ((*(stacks->stack_a + (stacks->top_a)) > *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1)) < *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2)) > *(stacks->stack_a + ((stacks->top_a)))))
		sa(stacks);
	else if ((*(stacks->stack_a + (stacks->top_a)) > *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1)) > *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2)) < *(stacks->stack_a + ((stacks->top_a)))))
		{
			sa(stacks);
			rra(stacks);
		}
	 else if ((*(stacks->stack_a + (stacks->top_a)) > *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1)) < *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2)) < *(stacks->stack_a + ((stacks->top_a)))))
	{
		ra(stacks);
	}
	
	else if ((*(stacks->stack_a + (stacks->top_a)) < *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1)) > *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2)) > *(stacks->stack_a + ((stacks->top_a)))))
	{
		sa(stacks);
		ra(stacks);
	}
	
	else if ((*(stacks->stack_a + (stacks->top_a)) < *(stacks->stack_a + ((stacks->top_a) - 1)))
		&& (*(stacks->stack_a + ((stacks->top_a) - 1)) > *(stacks->stack_a + ((stacks->top_a) - 2)))
		&& (*(stacks->stack_a + (stacks->top_a - 2)) < *(stacks->stack_a + ((stacks->top_a)))))
	{
		rra(stacks);
	} 
}
