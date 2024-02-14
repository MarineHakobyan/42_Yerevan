/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:48:18 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:48:20 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
 

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_matrix_len(char **arr);
int			ft_is_number(char *s);
void		ft_putstr(char *s);
void		exit_with_error(char *s);

int			*sort_int_tab(int *nums, int size);
int			*int_index(int *nums, int size);
int			*tab_index(int *nums, int *tab, int size);
void		validate_integer(int minus, long int n);
void		check_if_unique_nums(int *nums, int len);

t_data		intput_stack(int *nums, int i);
t_data		indexate_stack(t_data stack);
t_stack		*ft_lstnew(int content, int i);
int			list_len(t_stack *ab);

void		choose_sort_method(t_data stack);
void		sort_first_three(t_data stack);
void		sort_small(t_data stack);
void		butterfly_sort(t_data stack);
int			find_n(t_data stack);
int			ft_end(t_data stack);
int			ft_if_sort_b(t_stack *ab);

#endif
