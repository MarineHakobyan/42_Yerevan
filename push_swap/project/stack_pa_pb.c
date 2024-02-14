/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:49:24 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:49:26 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	stack_pa(t_data stack, int fd)
{
	t_stack	*tmp;

	if (stack.a == NULL)
	{
		stack.a = stack.b;
		stack.b = stack.b->next;
		stack.a->next = NULL;
	}
	else
	{
		tmp = stack.a;
		stack.a = stack.b;
		stack.b = stack.b->next;
		stack.a->next = tmp;
	}
	if (fd == 1)
		write (1, "pa\n", 3);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_pb(t_data stack, int fd)
{
	t_stack	*tmp;

	if (stack.b == NULL)
	{
		stack.b = stack.a;
		stack.a = stack.a->next;
		stack.b->next = NULL;
	}
	else
	{
		tmp = stack.b;
		stack.b = stack.a;
		stack.a = stack.a->next;
		stack.b->next = tmp;
	}
	if (fd == 1)
		write (1, "pb\n", 3);
	stack = indexate_stack(stack);
	return (stack);
}
