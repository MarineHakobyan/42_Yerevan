/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:49:58 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:50:00 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content, int i)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = content;
	new->index = i;
	new->next = NULL;
	return (new);
}

int	*tab_index(int *nums, int *tab, int size)
{
	int	i;
	int	j;
	int	*index;

	index = (int *)malloc(sizeof(int *) * size);
	if (!index)
		return (0);
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (nums[i] != tab[j])
			++j;
		index[i] = j;
	}
	i = -1;
	while (++i < size)
		tab[i] = index[i];
	free (index);
	return (tab);
}

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	flag;

	i = 0;
	flag = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
			flag = 1;
		}
		else
			++i;
	}
	if (flag == 0)
		exit (0);
	return (tab);
}

int	*int_index(int *nums, int size)
{
	int	*table;
	int	i;

	table = (int *)malloc(sizeof(int *) * size);
	if (!table)
		return (0);
	i = -1;
	while (++i < size)
		table[i] = nums[i];
	table = sort_int_tab(table, size);
	return (tab_index(nums, table, size));
}

int	list_len(t_stack *ab)
{
	int	i;

	i = 0;
	while (ab != NULL)
	{
		ab = ab->next;
		++i;
	}
	return (i);
}
