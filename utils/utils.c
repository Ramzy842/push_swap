/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:46:07 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/10 22:49:02 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_args_length(char **av)
{
	int		x;
	int		y;
	int		len;
	char	**str;

	x = 1;
	len = 0;
	while (av[x])
	{
		str = ft_split(av[x], ' ');
		y = 0;
		while (str[y])
		{
			y++;
			len++;
		}
		x++;
	}
	return (len);
}

char	*join_args(char *str, char **av, int *x)
{
	while (av[*x])
	{
		str = ft_strjoin(str, av[*x]);
		str = ft_strjoin(str, " ");
		(*x)++;
	}
	return (str);
}

int	check_values(char **av, int length)
{
	int			x;
	char		**splitted;
	char		*str;
	long long	arg;

	x = 1;
	str = malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	str = join_args(str, av, &x);
	splitted = ft_split(str, ' ');
	x = 0;
	while (splitted[x])
	{
		arg = ft_atoi(splitted[x]);
		if ((arg < INT_MIN || arg > INT_MAX)
			|| has_dup(arg, splitted, length)
			|| !is_number(splitted[x]))
			display_error();
		x++;
	}
	return (1);
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
