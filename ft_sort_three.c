/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:34:13 by zbechtle          #+#    #+#             */
/*   Updated: 2025/03/22 00:52:30 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, 0);
	else if ((*a)->next == biggest_node)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}
