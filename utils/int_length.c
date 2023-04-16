/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:03:26 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/10 22:46:43 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	int_length(int *array)
{
	int	length;
	int	x;

	x = 0;
	length = 0;
	while (*(array + x))
	{
		x++;
		length++;
	}
	return (length);
}
