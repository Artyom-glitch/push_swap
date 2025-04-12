/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:14:21 by zbechtle          #+#    #+#             */
/*   Updated: 2025/04/12 22:42:20 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		if (result < -2147483648 || result > 2147483647)
			return (2147483648);
		str++;
	}
	return (result * sign);
}

void	check_arguments(char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(NULL);
		n = ft_atol(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			free_errors(NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	check_arguments(argv + 1);
	stack_creator(&a, argv + 1);
	if (!stack_is_sorted(a))
		what_sort(&a, &b);
	free_stack(&a);
	return (0);
}

void	what_sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		sa(a, 0);
	else if (stack_size(*a) == 3)
		sort_3(a);
	else
		sort_turk(a, b);
}
