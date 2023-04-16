/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:01:17 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/16 05:44:58 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	int	top_a;
	int	top_b;
	int	*stack_a;
	int	*stack_b;
	int	length;
}	t_stack;

char		**ft_split(char *s, char c);
size_t		ft_strlen(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		ft_strlen_2d(char **str);
long long	ft_atoi(char *str);
int			read_args(char **av);
int			store_value(char **av, int l);
int			ft_isdigit(int arg);
void		display_error(void);
int			has_dup(long long nb, char **av, int length);
int			is_number(char *arg);
char		*ft_strjoin(char *s1, char *s2);
int			get_args_length(char **av);
int			check_values(char **av, int length);
char		*join_args(char *str, char **av, int *x);
int			int_length(int *array);
void		swap(int *x, int *y);
void		sort_three(t_stack *stacks);
void		sort_four(t_stack *stacks);
int			extract_smallest(t_stack *s);
int			extract_index_smallest(t_stack *s);
void		sort_more(t_stack *stacks, int *temp_arr, int length);
void		sort_five(t_stack *stacks);

// ops
void		sa(t_stack *stacks);
void		pa(t_stack *stacks);
void		ra(t_stack *stacks);
void		rra(t_stack *stacks);

void		sb(t_stack *stacks);
void		pb(t_stack *stacks);
void		rb(t_stack *stacks);
void		rrb(t_stack *stacks);
#endif