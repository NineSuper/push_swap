/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:17 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/15 18:42:24 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_b(t_push *s_push)
{
	int	first;
	int	temp;
	int	i;

	if (s_push->len_b < 2)
		return ;
	i = s_push->len_b;
	first = s_push->b[i - 1];
	i--;
	while (i--)
	{
		temp = s_push->b[i];
		s_push->b[i + 1] = temp;
	}
	s_push->b[0] = first;
	if (s_push->rr == 0)
		ft_printf("rrb\n");
}

void	ft_reverse_a(t_push *s_push)
{
	int	first;
	int	temp;
	int	i;

	if (s_push->len_a < 2)
		return ;
	i = s_push->len_a;
	first = s_push->a[i - 1];
	i--;
	while (i--)
	{
		temp = s_push->a[i];
		s_push->a[i + 1] = temp;
	}
	s_push->a[0] = first;
	if (s_push->rr == 0)
		ft_printf("rra\n");
}

void	ft_reverse_ab(t_push *s_push)
{
	if (s_push->len_a < 2)
		ft_reverse_b(s_push);
	else if (s_push->len_b < 2)
		ft_reverse_a(s_push);
	else
	{
		s_push->rr = 1;
		ft_reverse_a(s_push);
		ft_reverse_b(s_push);
		ft_printf("rr\n");
	}
	s_push->rr = 0;
}
