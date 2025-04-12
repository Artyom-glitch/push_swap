/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:24:48 by zbechtle          #+#    #+#             */
/*   Updated: 2025/03/22 00:49:24 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, 0);
	update_index(*a);
	update_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, 0);
	update_index(*a);
	update_index(*b);
}

static void	mover(t_stack **a, t_stack **b, int side)
{
	t_stack	*cheapest_node;

	if (side == 0)
	{
		cheapest_node = get_cheapest(*a);
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			rev_rotate_both(a, b, cheapest_node);
		prep_for_push(a, cheapest_node, 'a');
		prep_for_push(b, cheapest_node->target_node, 'b');
		pb(b, a, 0);
	}
	else
	{
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b, 0);
	}
}

static void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort_turk(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, 0);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, 0);
	while (len_a-- > 3 && !stack_is_sorted(*a))
	{
		anode_initializer(*a, *b);
		mover(a, b, 0);
	}
	sort_3(a);
	while (*b)
	{
		bnode_initializer(*a, *b);
		mover(a, b, 1);
	}
	update_index(*a);
	min_on_top(a);
}
