/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:16:19 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/17 09:19:18 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int binary_search(int *arr, int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binary_search(arr, value, start, mid - 1);
        }
        return binary_search(arr, value, mid + 1, end);
    }
    return -1;
}

int extract_num_index(int value, int *temp_arr, int top) {
    int index = binary_search(temp_arr, value, 0, top);
    return index;
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

void	sort_more(t_stack *stacks, int *temp_arr)
{
	int	cte;
	int	range_movement;
	int *arr = stacks->stack_a;
	int top = stacks->top_a;
	int	x;

	x = 0;
	range_movement = 0;
	if (top + 1 <= 100)
		cte = 15;
	else
		cte = 35;

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
		extract_biggest(stacks, &biggest_num, &index);
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