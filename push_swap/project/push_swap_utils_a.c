/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:48:33 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:48:36 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_sotr_a(t_data stack)
{
	t_stack	*tmp;

	tmp = stack.a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_if_sort_b(t_stack *ab)
{
	t_stack	*tmp;
	int		len;

	len = list_len(ab);
	if (len == 1)
		return (1);
	tmp = ab;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_data	ft_3_sorting(t_data stack)
{
	int		len;

	len = list_len(stack.a);
	if (stack.a->data == stack.size - 1)
	{
		stack = stack_ra(stack, 1);
		if (ft_if_sotr_a(stack) == 1)
			stack = stack_sa(stack, 1);
	}
	else if (stack.a->next->data == stack.size - 1)
	{
		stack = stack_rra(stack, 1);
		if (ft_if_sotr_a(stack) == 1)
			stack = stack_sa(stack, 1);
	}
	else if (stack.a->next->next->data == stack.size - 1)
	{
		if (ft_if_sotr_a(stack) == 1)
			stack = stack_sa(stack, 1);
	}
	return (stack);
}

void	sort_small(t_data stack)
{
	int		i;
	int		len_a;

	i = 0;
	while (ft_end(stack) == 1)
	{
		if (stack.a->data == i)
		{
			stack = stack_pb(stack, 1);
			++i;
		}
		else
			stack = stack_ra_or_rra(stack, i);
		len_a = list_len(stack.a);
		if (len_a == 3)
		{
			stack = ft_3_sorting(stack);
			while (stack.b)
				stack = stack_pa(stack, 1);
		}
	}
}
