/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:49:47 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:49:50 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	stack_rra(t_data stack, int fd)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (stack.a != NULL && stack.a->next != NULL)
	{
		tmp = stack.a;
		while (stack.a->next->next != NULL)
			stack.a = stack.a->next;
		tmp1 = stack.a->next;
		stack.a->next = NULL;
		stack.a = tmp;
		tmp1->next = stack.a;
		stack.a = tmp1;
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "rra\n", 4);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_rrb(t_data stack, int fd)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (stack.b != NULL && stack.b->next != NULL)
	{
		tmp = stack.b;
		while (stack.b->next->next != NULL)
			stack.b = stack.b->next;
		tmp1 = stack.b->next;
		stack.b->next = NULL;
		stack.b = tmp;
		tmp1->next = stack.b;
		stack.b = tmp1;
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "rrb\n", 4);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_rrr(t_data stack, int fd)
{
	if (stack.a && stack.a->next && stack.b && stack.b->next)
	{
		stack = stack_rra(stack, 0);
		stack = stack_rrb(stack, 0);
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "rrr\n", 4);
	return (stack);
}
