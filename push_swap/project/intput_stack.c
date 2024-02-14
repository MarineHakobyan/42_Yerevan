/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intput_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:48:59 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:49:01 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	intput_stack(int *nums, int len)
{
	t_data	stack;
	t_stack	*cursor;
	int		i;
	int		*index_num;

	i = 0;
	index_num = int_index(nums, len);
	stack.a = ft_lstnew(index_num[0], i);
	cursor = stack.a;
	while (++i < len)
	{
		cursor->next = ft_lstnew(index_num[i], i);
		cursor = cursor->next;
	}
	stack.b = NULL;
	stack.size = len;
	free (index_num);
	return (stack);
}

t_data	indexate_stack(t_data stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	i = 0;
	tmp1 = stack.a;
	tmp2 = stack.b;
	while (stack.a != NULL)
	{
		stack.a->index = i;
		stack.a = stack.a->next;
		++i;
	}
	i = 0;
	while (stack.b != NULL)
	{
		stack.b->index = i;
		stack.b = stack.b->next;
		++i;
	}
	stack.a = tmp1;
	stack.b = tmp2;
	return (stack);
}
