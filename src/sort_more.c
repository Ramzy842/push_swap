/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:16:19 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/22 05:26:23 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* int binary_search(int *arr, int value, int start, int end) {
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
} */

void	send_to_stack_b(t_stack *stacks, int cte, int *arr, int *temp_arr)
{
	int	range_movement;
	int	extracted_num;

	range_movement = 0;
	while (stacks->top_a != -1)
	{
		extracted_num = extract_num_index(arr[stacks->top_a],
				temp_arr, stacks->length - 1);
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
}

void	first_part(t_stack *stacks, int *temp_arr)
{
	int	cte;
	int	*arr;

	arr = stacks->stack_a;
	if (stacks->length <= 100)
		cte = 15;
	else
		cte = 35;
	send_to_stack_b(stacks, cte, arr, temp_arr);
}

void	second_part(t_stack *stacks)
{
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

void	sort_more(t_stack *stacks, int *temp_arr)
{
	first_part(stacks, temp_arr);
	second_part(stacks);
}

/* void	sort_more(t_stack *stacks, int *temp_arr)
{
	int	cte;
	int	range_movement;
	int	*arr;
	int	x;
	int extracted_num;

	arr = stacks->stack_a;
	x = 0;
	range_movement = 0;
	if (stacks->length <= 100)
		cte = 15;
	else
		cte = 40;
	while (stacks->top_a != -1)
	{
		extracted_num = extract_num_index(arr[stacks->top_a],
			temp_arr, stacks->length - 1);
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
} */
