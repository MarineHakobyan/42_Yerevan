/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:47:03 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:47:05 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] == ' ')
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		++i;
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	while (s[i])
	{
		if (s[i] == ' ')
			++i;
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

int	ft_matrix_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

void	check_if_unique_nums(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (nums && i < size)
	{
		j = i + 1;
		while (nums && j < size)
			if (nums[i] == nums [j++])
				exit_with_error("Error\n");
		++i;
	}
	return ;
}
