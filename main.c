/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:14:21 by zbechtle          #+#    #+#             */
/*   Updated: 2025/04/12 20:06:11 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	stack_creator(&a, argv + 1);
	if (!stack_is_sorted(a))
		what_sort(a, b);
	free_stack(&a);
	return (0);
}

void	what_sort(t_stack *a, t_stack *b)
{
	if (stack_size(a) == 2)
		sa(&a, 0);
	else if (stack_size(a) == 3)
		sort_3(&a);
	else
		sort_turk(&a, &b);
}
