/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:27:18 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/17 11:06:33 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isgood(int *array, t_push *s_push)
{
	int	i;

	i = 0;
	if (s_push->len_a == 2)
	{
		if (array[0] > array[1])
		{
			ft_swap_a(s_push);
			return (1);
		}
		return (0);
	}
	if (array[0] > array[1])
		return (1);
	i++;
	while (i < s_push->len_a)
	{
		if (array[i - 1] > array[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_suite(int *array, int n, int index, t_push *s_push)
{
	while (array[0] != n)
	{
		if (n == array[1])
			ft_swap_a(s_push);
		else if (index > s_push->len_a / 2)
			ft_reverse_a(s_push);
		else
			ft_rotate_a(s_push);
	}
}

void	checkmax(int *array, int n, t_push *s_push)
{
	int	i;
	int	index;

	i = 0;
	if (isgood(s_push->a, s_push) == 0)
		return ;
	while (i != s_push->len_a)
	{
		if (n > array[i])
		{
			n = array[i];
			index = i;
		}
		i++;
	}
	ft_suite(array, n, index, s_push);
	if (isgood(s_push->a, s_push) == 1)
		ft_push_b(s_push);
}

void	ft_algo_for_three(t_push *s_push)
{
	if (s_push->a[0] > s_push->a[1] && s_push->a[1] > s_push->a[2])
	{
		ft_swap_a(s_push);
		ft_reverse_a(s_push);
	}
	if (s_push->a[0] > s_push->a[1] && s_push->a[0] < s_push->a[2])
		ft_swap_a(s_push);
	if (s_push->a[0] > s_push->a[1] && s_push->a[1] < s_push->a[2])
		ft_rotate_a(s_push);
	while (s_push->len_a)
	{
		if (isgood(s_push->a, s_push) == 0)
			break ;
		checkmax(s_push->a, s_push->a[0], s_push);
	}
	while (s_push->len_b)
		ft_push_a(s_push);
}

void	ft_algo(t_push *s_push)
{
	if (s_push->len_a < 3)
		isgood(s_push->a, s_push);
	if (s_push->len_a == 3)
		ft_algo_for_three(s_push);
	else if (s_push->len_a < 100)
	{
		while (s_push->len_a)
		{
			if (isgood(s_push->a, s_push) == 0)
				break ;
			checkmax(s_push->a, s_push->a[0], s_push);
		}
		while (s_push->len_b)
			ft_push_a(s_push);
	}
	else
		ft_big_algo(s_push, 0, 0);
}
