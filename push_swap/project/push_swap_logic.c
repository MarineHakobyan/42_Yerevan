/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:48:08 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:48:11 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_end(t_data stack)
{
	t_stack	*tmp;

	tmp = stack.a;
	while (tmp->next && stack.b == NULL)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	if (!stack.b)
	{
		while (stack.a)
		{
			free(stack.a);
			stack.a = stack.a->next;
		}
		free (stack.a);
		exit (0);
	}
	else
		return (1);
}

void	sort_first_three(t_data stack)
{
	int		len;

	len = list_len(stack.a);
	if (stack.a->data == len - 1)
	{
		stack = stack_ra(stack, 1);
		ft_end(stack);
		stack = stack_sa(stack, 1);
	}
	else if (stack.a->next->data == len - 1)
	{
		stack = stack_rra(stack, 1);
		ft_end(stack);
		stack = stack_sa(stack, 1);
	}
	else if (stack.a->next->next->data == len - 1)
	{
		stack = stack_sa(stack, 1);
	}
	ft_end(stack);
}
