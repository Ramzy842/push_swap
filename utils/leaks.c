/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:47:52 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/10 15:54:42 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_2d_array(char **s)
{
	int	x;

	x = 0;
	while (s[x] != NULL)
	{
		free(s[x]);
		x++;
	}
	free(s);
}