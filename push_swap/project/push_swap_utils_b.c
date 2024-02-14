/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:48:47 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:48:49 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_n(t_data stack)
{
	int	n;

	n = 1;
	if (stack.size <= 100)
		n = stack.size * 15 / 100;
	else if (stack.size <= 200)
		n = stack.size * 20 / 350;
	else if (stack.size <= 450)
		n = stack.size * 25 / 350;
	else
		n = 30;
	return (n);
}

t_data	push_b_back_to_a(t_data stack)
{
	int	i;

	i = list_len(stack.b) - 1;
	stack = ft_3_sorting(stack);
	while (stack.b != NULL)
	{
		i = list_len(stack.b) - 1;
		if (stack.b->data == i)
			stack = stack_pa(stack, 1);
		else
			stack = stack_rb_or_rrb(stack, i);
	}
	return (stack);
}

void	butterfly_sort(t_data stack)
{
	int	count;
	int	n;

	count = 0;
	n = find_n(stack);
	while (ft_end(stack) == 1)
	{
		if (stack.a->data <= count + n && stack.a->data < stack.size - 3)
		{
			stack = stack_pb(stack, 1);
			++count;
		}
		else if (stack.a->data <= count && stack.a->data < stack.size - 3)
		{
			stack = stack_pb(stack, 1);
			stack = stack_rb(stack, 1);
			++count;
		}
		else
			stack = stack_ra(stack, 1);
		if (list_len(stack.a) == 3)
			stack = push_b_back_to_a(stack);
	}
}
