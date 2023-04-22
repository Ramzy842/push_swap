/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:01:17 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/22 05:26:01 by rchahban         ###   ########.fr       */
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
int			has_dup(long long nb, char **av, size_t length);
int			is_sorted(int *arr, int length);
int			is_number(char *arg);
char		*ft_strjoin(char *s1, char *s2);
int			get_args_length(char **av);
int			check_values(int *length, char **splitted);
char		*join_args(char *str, char **av, int *x);
int			int_length(int *array);
void		swap(int *x, int *y);
void		sort_three(t_stack *stacks);
void		sort_four(t_stack *stacks);
int			extract_smallest(t_stack *s);
int			extract_index_smallest(t_stack *s);
void		sort_more(t_stack *stacks, int *temp_arr);
void		sort_five(t_stack *stacks);
void		extract_biggest(t_stack *s, int *number, int *index);
int			extract_num_index(int value, int *temp_arr, int top);
int			check_args_validity(int ac, char **av, char **splitted);
char		**split_args(char **av);
void		free_splitted(char **splitted, int len);
void		free_stacks(int *stack, int len);
int			*sort_temp_array(int *stack, int length);
int			is_sorted(int *arr, int length);
int			*fill_arr(int *arr, char **splitted, int len);
void		fill_stack(t_stack *stacks, char **splitted);
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