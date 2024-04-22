/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:29:34 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/15 18:42:24 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_push *s_push)
{
	int	temp;
	int	i;

	if (s_push->len_a <= 1)
		return ;
	i = 0;
	temp = s_push->a[0];
	while (i + 1 < s_push->len_a)
	{
		s_push->a[i] = s_push->a[i + 1];
		i++;
	}
	s_push->a[i] = temp;
	if (s_push->rr == 0)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_push *s_push)
{
	int	temp;
	int	i;

	if (s_push->len_b <= 1)
		return ;
	i = 0;
	temp = s_push->b[0];
	while (i + 1 < s_push->len_b)
	{
		s_push->b[i] = s_push->b[i + 1];
		i++;
	}
	s_push->b[i] = temp;
	if (s_push->rr == 0)
		ft_printf("rb\n");
}

void	ft_rotate_ab(t_push *s_push)
{
	if (s_push->len_a < 2)
		ft_rotate_b(s_push);
	else if (s_push->len_b < 2)
		ft_rotate_a(s_push);
	else
	{
		s_push->rr = 1;
		ft_rotate_a(s_push);
		ft_rotate_b(s_push);
		ft_printf("rr\n");
	}
	s_push->rr = 0;
}
