/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:49:16 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:49:18 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	stack_ra(t_data stack, int fd)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (stack.a != NULL && stack.a->next != NULL)
	{
		tmp = stack.a;
		tmp1 = stack.a->next;
		while (stack.a->next != NULL)
			stack.a = stack.a->next;
		stack.a->next = tmp;
		stack.a->next->next = NULL;
		stack.a = tmp1;
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "ra\n", 3);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_rb(t_data stack, int fd)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (stack.b != NULL && stack.b->next != NULL)
	{
		tmp = stack.b;
		tmp1 = stack.b->next;
		while (stack.b->next != NULL)
			stack.b = stack.b->next;
		stack.b->next = tmp;
		stack.b->next->next = NULL;
		stack.b = tmp1;
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "rb\n", 3);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_rr(t_data stack, int fd)
{
	if (stack.a && stack.a->next && stack.b && stack.b->next)
	{
		stack = stack_ra(stack, 0);
		stack = stack_rb(stack, 0);
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "rr\n", 3);
	return (stack);
}
