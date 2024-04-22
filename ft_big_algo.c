/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:05:54 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/15 18:42:24 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_c(int *array, int n, int p, t_push *s_push)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i != s_push->len_a)
	{
		if (n > array[i])
			index++;
		i++;
	}
	s_push->c[p] = index + 1;
}

void	ft_pile_c(t_push *s_push)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s_push->c = ft_calloc(1, sizeof(int) * s_push->len_a + 1);
	while (i != s_push->len_a)
	{
		ft_index_c(s_push->a, s_push->a[i], i, s_push);
		i++;
	}
	i = 0;
	while (i != s_push->len_a)
	{
		s_push->a[i] = s_push->c[i];
		i++;
	}
	free(s_push->c);
}

void	ft_big_algo(t_push *s_push, int i, int j)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = s_push->len_a;
	max_num = size - 1;
	max_bits = 0;
	i = 0;
	ft_pile_c(s_push);
	while (max_num >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((s_push->a[0] >> i) & 1)
				ft_rotate_a(s_push);
			else
				ft_push_b(s_push);
		}
		while (s_push->len_b)
			ft_push_a(s_push);
		i++;
	}
}
