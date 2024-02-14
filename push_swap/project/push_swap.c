/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:47:59 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:48:02 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort_method(t_data stack)
{
	if (stack.size <= 3)
		sort_first_three(stack);
	else if (stack.size > 3 && stack.size <= 65)
		sort_small(stack);
	else
		butterfly_sort(stack);
}

void	push_swap(char *str)
{
	t_data	stack;
	int		*num;
	char	**arr;
	int		len;
	int		i;

	i = 0;
	arr = ft_split(str, ' ');
	len = ft_matrix_len(arr);
	num = (int *)malloc(sizeof(int *) * len);
	while (arr[i])
	{
		num[i] = ft_atoi(arr[i]);
		free (arr[i]);
		i++;
	}
	free (arr);
	if (i == 1)
		exit (0);
	check_if_unique_nums(num, len);
	stack = intput_stack(num, len);
	choose_sort_method(stack);
	free (num);
}

int	main(int ac, char **av)
{
	char	*tiv;
	int		i;

	i = 0;
	if (ac >= 2)
	{
		while (av[++i] != '\0')
		{
			if (ft_is_number(av[i]) != 0)
			{
				tiv = ft_strjoin(tiv, av[i]);
				tiv = ft_strjoin(tiv, " ");
			}
			else
				exit_with_error("Error\n");
		}
		push_swap(tiv);
		free (tiv);
		exit(0);
	}
	return (0);
}
