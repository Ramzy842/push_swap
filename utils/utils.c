/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:46:07 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/17 09:41:48 by rchahban         ###   ########.fr       */
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

/* char	*join_args(char *str, char **av, int *x)
{
	while (av[*x])
	{
		str = ft_strjoin(str, av[*x]);
		str = ft_strjoin(str, " ");
		(*x)++;
	}
	return (str);
} */

char	*join_args(char *str, char **av, int *length)
{
    int x;
    char *temp;

    x = 1;
    while (av[x])
    {
        temp = ft_strjoin(str, av[x]);
        str = temp;
        temp = ft_strjoin(str, " ");
        str = temp;
        (*length)++;
        x++;
    }
    return (str);
}

int	check_values(int *length, char **splitted)
{
	int			x;
	long long	arg;

	x = 0;
	while (splitted[x])
	{
		arg = ft_atoi(splitted[x]);
		if ((arg < INT_MIN || arg > INT_MAX)
			|| has_dup(arg, splitted, length)
			|| !is_number(splitted[x]))
			display_error();
		x++;
		(*length)++;
	}
	return (*length);
}




/* int	count_args(char **args)
{
    int count = 0;
    while (*args)
    {
        count++;
        args++;
    }
    return count;
} */

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
