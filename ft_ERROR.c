/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ERROR.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:34:13 by zbechtle          #+#    #+#             */
/*   Updated: 2025/04/12 20:05:59 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	error_syntax(char *arg)
{
	if (!(*arg == '+' || *arg == '-' || (*arg >= '0' && *arg <= '9')))
		return (1);
	if ((*arg == '+' || *arg == '-')
		&& !(arg[1] >= '0' && arg[1] <= '9'))
		return (1);
	while (*++arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

# include <stdio.h>

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->value);
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
