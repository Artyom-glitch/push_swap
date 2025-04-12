/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:21:16 by zbechtle          #+#    #+#             */
/*   Updated: 2025/04/12 22:00:08 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					error_syntax(char *str_n);
int					error_duplicate(t_stack *a, int n);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a);
void				stack_creator(t_stack **a, char **argv);
t_stack				*get_cheapest(t_stack *stack);
void				prep_for_push(t_stack **s, t_stack *n, char c);
void				free_args(char **argv);
void				anode_initializer(t_stack *a, t_stack *b);
void				update_index(t_stack *stack);
void				set_cheapest(t_stack *stack);
void				bnode_initializer(t_stack *a, t_stack *b);
int					stack_size(t_stack *stack);
int					stack_is_sorted(t_stack *stack);
t_stack				*find_last(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);
void				sort_3(t_stack **a);
void				sort_turk(t_stack **a, t_stack **b);
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **b, t_stack **a, int print);
void				what_sort(t_stack **a, t_stack **b);
char				*get_next_word(char *s, char c);

#endif