/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:41:57 by rchahban          #+#    #+#             */
/*   Updated: 2023/05/10 23:02:40 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	initialize_stacks(t_stack *stacks, int argc,
	char **argv, char **splitted)
{
	stacks->length = check_args_validity(argc, argv, splitted);
	stacks->stack_a = malloc(stacks->length * sizeof(int));
	stacks->top_a = -1;
	stacks->top_b = -1;
}

void	handle_less_than_three(t_stack *stacks)
{
	if (stacks->length <= 1)
		return ;
	else if (stacks->length == 2)
	{
		if (stacks->stack_a[0] > stacks->stack_a[1])
			sa(stacks);
	}
	else if (stacks->length == 3)
		sort_three(stacks);
}

void	handle_more(t_stack *stacks, int *temp_arr, char **splitted)
{
	stacks->stack_b = malloc(stacks->length * sizeof(int));
	if (stacks->length == 4)
		sort_four(stacks);
	else if (stacks->length == 5)
		sort_five(stacks);
	else
	{
		temp_arr = fill_arr(temp_arr, splitted, stacks->length);
		temp_arr = sort_temp_array(temp_arr, stacks->length);
		sort_more(stacks, temp_arr);
	}
	free(temp_arr);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	//int		x;
	int		*temp_arr;
	char	**splitted;

	//x = 0;
	stacks = malloc(sizeof(t_stack));
	temp_arr = NULL;
	splitted = split_args(argv);
	initialize_stacks(stacks, argc, argv, splitted);
	fill_stack(stacks, splitted);
	if (is_sorted(stacks->stack_a, stacks->length))
		return (0);
	else if (stacks->length <= 3)
		handle_less_than_three(stacks);
	else
		handle_more(stacks, temp_arr, splitted);
	free (stacks->stack_a);
	free (stacks->stack_b);
	return (0);
}
