/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:30:42 by zbechtle          #+#    #+#             */
/*   Updated: 2025/04/12 20:17:15 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

# include <stdio.h>

static void	swap(t_stack **head)
{
	int	buffer;
	if (!*head || !(*head)->next)
		return ;

	printf("zz %d\n", (*head)->value);
	buffer = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = buffer;
	// *head = (*head)->next;
	// (*head)->prev->prev = *head;
	// (*head)->prev->next = (*head)->next;
	// if ((*head)->next)
	// 	(*head)->next->prev = (*head)->prev;
	// (*head)->next = (*head)->prev;
	// (*head)->prev = NULL;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (print == 0)
		write(1, "ss\n", 3);
}
