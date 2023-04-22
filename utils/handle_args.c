/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:21:04 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/22 05:26:53 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_args(char **av)
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
	free(str);
	return (splitted);
}

int	check_args_validity(int ac, char **av, char **splitted)
{
	int	length;

	(void) av;
	length = 0;
	if (ac >= 2)
		length = check_values(&length, splitted);
	return (length);
}
