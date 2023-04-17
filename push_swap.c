/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:41:57 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/17 09:55:24 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char **split_args(char **av)
{
	(void) av;
	int			x;
	char		**splitted;
	char		*str;

	x = 1;
	str = malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	str = join_args(str, av, &x);
	splitted = ft_split(str, ' ');
	return (splitted);
}

void	fill_stack(t_stack *stacks, char **splitted)
{
	int y = stacks->length;
	while (y > 0)
	{
		(stacks->top_a)++;
		*(stacks->stack_a + (stacks->top_a)) = ft_atoi(splitted[y - 1]);
		y--;
	}
} 

int	*fill_arr(int *arr, char **splitted, int len)
{
	int			x;

	arr =(int*) malloc(len * sizeof(int));
	x = 0;
	while (x < len)
	{
		*(arr + x) = ft_atoi(splitted[x]);
		x++;
	}
	return (arr);
}

int	check_args_validity(int ac, char **av, char **splitted)
{
	int	length;
	(void) av;
	length = 0;
	if (ac >= 2)
		length = check_values(&length, splitted);
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
        if (arr[x] < arr[x+1]) 
            return 0;
        x++;
    }
    return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		x;
	int		*temp_arr;
	char	**splitted;

	x = 0;
	splitted = split_args(argv);
	stacks = malloc(sizeof(stacks));
	temp_arr = NULL;
	stacks->length = check_args_validity(argc, argv, splitted);
	stacks->stack_a = (int*)malloc(stacks->length * sizeof(int));
	stacks->top_a = -1;
	stacks->top_b = -1;
	fill_stack(stacks, splitted);
	if (is_sorted(stacks->stack_a, stacks->length))
		return (0);
	else if (stacks->length <= 3)
	{
		if (stacks->length == 2)
			sa(stacks);
		else if (stacks->length == 3)
			sort_three(stacks);
	}
	else
	{
		stacks->stack_b = (int*)malloc(stacks->length * sizeof(int));
		if (stacks->length == 4)
			sort_four(stacks);
		else if (stacks->length == 5)
			sort_five(stacks);
		else
		{
			temp_arr = fill_arr(temp_arr, argv, stacks->length);
			temp_arr = sort_temp_array(temp_arr, stacks->length);
			sort_more(stacks, temp_arr);
		}
	}
	/* x = 0;
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
		}		 */
	//free(stacks->stack_a);
	//free(stacks->stack_b);
	//free(stacks);
	/* while (1)
		; */
	
	return (0);
}
