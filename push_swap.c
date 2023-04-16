/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:41:57 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/16 06:05:56 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	fill_stack(int *stack, char **av, int *top, int length)
{
	int			x;
	char		**splitted;
	char		*str;

	x = 1;
	str = malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	str = join_args(str, av, &x);
	splitted = ft_split(str, ' ');
	x = 0;
	int y = length;
	while (y > 0)
	{
		(*top)++;
		*(stack + x) = ft_atoi(splitted[y - 1]);
		x++;
		y--;
	}
} 

int	*fill_arr(int *arr, char **av)
{
	int			x;
	char		**splitted;
	char		*str;

	x = 1;
	str = malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	str = join_args(str, av, &x);
	splitted = ft_split(str, ' ');
	arr =(int*) malloc(ft_strlen_2d(splitted) * sizeof(int));
	x = 0;
	while (x < (int)ft_strlen_2d(splitted))
	{
		*(arr + x) = ft_atoi(splitted[x]);
		x++;
	}
	return (arr);
}

int	check_args_validity(int ac, char **av)
{
	int	length;

	length = get_args_length(av);
	if (ac >= 2)
		check_values(av, length);
	return length;
}

int	*sort_temp_array(int *stack, int length)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
    while (x < length - 1) 
	{
        while (y < length - x - 1) 
		{
            if (stack[y] > stack[y + 1]) 
                swap(&stack[y], &stack[y + 1]);
            y++;
        }
        x++;
        y = 0;
    }
	return (stack);
}

int is_sorted(int *arr, int length) {
    int x;

	x = 0;
    while (x < length - 1) 
	{
        if (arr[x] < arr[x+1]) {
            return 0;
        }
        x++;
    }
    return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		x;
	int		*temp_arr;

	x = 0;
	stacks = malloc(sizeof(stacks));
	stacks->top_a = -1;
	stacks->top_b = -1;
	stacks->length = check_args_validity(argc, argv);
	temp_arr = NULL;
	stacks->stack_a = (int*)malloc(stacks->length * sizeof(int));
	stacks->stack_b = (int*)malloc(stacks->length * sizeof(int));
	temp_arr = fill_arr(temp_arr, argv);
	temp_arr = sort_temp_array(temp_arr, stacks->length);
	fill_stack(stacks->stack_a, argv, &(stacks->top_a), stacks->length);
	if (is_sorted(stacks->stack_a, stacks->length))
		return (0);
	else
	{
		if (stacks->length == 2)
			sa(stacks);
		else if (stacks->length == 3)
			sort_three(stacks);
		else if (stacks->length == 4)
			sort_four(stacks);
		else if (stacks->length == 5)
			sort_five(stacks);
		else
			sort_more(stacks, temp_arr, stacks->length);
	}
	/* x = 0;
	printf("stacks length: %d\n", stacks->length);
	printf("Stack A: ");
	while (x <= stacks->top_a)
	{
		printf("%d ", stacks->stack_a[stacks->top_a - x]);
		x++;
	}
	printf("\n");
	x = 0;
	printf("Stack B: ");
	while (x <= stacks->top_b)
	{
		printf("%d ", stacks->stack_b[stacks->top_b - x]);
		x++;
	}
	printf("\n"); */
	return (0);
}
