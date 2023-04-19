/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:17:34 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/19 10:29:14 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_splitted(char **splitted, int len)
{
	int	x;

	x = 0;
	while (x < len)
	{
		free(splitted[x]);
		x++;
	}
	free(splitted);
}

void	free_stacks(int *stack, int len)
{
	int	x;

	x = 0;
	while (x < len)
	{
		free(&stack[x]);
		x++;
	}
	free(stack);
}
