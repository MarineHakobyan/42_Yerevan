/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:47:30 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:47:33 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	stack_ra_or_rra(t_data stack, int i)
{
	t_stack	*tmp;
	int		len;
	int		j;

	j = 0;
	len = list_len(stack.a);
	tmp = stack.a;
	while (tmp && tmp->data != i)
	{
		tmp = tmp->next;
		++j;
	}
	if (j <= len / 2)
		stack = stack_ra(stack, 1);
	else
		stack = stack_rra(stack, 1);
	return (stack);
}

t_data	stack_rb_or_rrb(t_data stack, int i)
{
	t_stack	*tmp;
	int		len;
	int		j;

	j = 0;
	len = list_len(stack.b);
	tmp = stack.b;
	while (tmp && tmp->data != i)
	{
		tmp = tmp->next;
		++j;
	}
	if (j <= len / 2)
		stack = stack_rb(stack, 1);
	else
		stack = stack_rrb(stack, 1);
	return (stack);
}
