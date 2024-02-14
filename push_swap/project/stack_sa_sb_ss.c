/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:50:09 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:50:18 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	stack_sa(t_data stack, int fd)
{
	int		tmp_d[2];
	t_stack	*tmp;

	if (stack.a && stack.a->next)
	{
	tmp = stack.a;
	tmp_d[0] = stack.a->data;
	stack.a = stack.a->next;
	tmp_d[1] = stack.a->data;
	stack.a->data = tmp_d[0];
	stack.a = tmp;
	stack.a->data = tmp_d[1];
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "sa\n", 3);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_sb(t_data stack, int fd)
{
	int		tmp_d[2];
	t_stack	*tmp;

	if (stack.b && stack.b->next)
	{
		tmp = stack.b;
		tmp_d[0] = stack.b->data;
		stack.b = stack.b->next;
		tmp_d[1] = stack.b->data;
		stack.b->data = tmp_d[0];
		stack.b = tmp;
		stack.b->data = tmp_d[1];
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "sb\n", 3);
	stack = indexate_stack(stack);
	return (stack);
}

t_data	stack_ss(t_data stack, int fd)
{
	if (stack.a && stack.a->next && stack.b && stack.b->next)
	{
		stack = stack_sa(stack, 0);
		stack = stack_sb(stack, 0);
	}
	else
		return (stack);
	if (fd == 1)
		write (1, "ss\n", 3);
	return (stack);
}
