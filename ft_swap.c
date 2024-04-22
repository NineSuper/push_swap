/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:41:09 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/15 18:48:52 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_push *s_push)
{
	int	temp;

	if (s_push->len_a <= 1)
		return ;
	temp = s_push->a[1];
	s_push->a[1] = s_push->a[0];
	s_push->a[0] = temp;
	ft_printf("sa\n");
}

void	ft_swap_b(t_push *s_push)
{
	int	temp;

	if (s_push->len_b <= 1)
		return ;
	temp = s_push->b[1];
	s_push->b[1] = s_push->b[0];
	s_push->b[0] = temp;
	ft_printf("sb\n");
}

void	ft_swap_ss(t_push *s_push)
{
	ft_swap_a(s_push);
	ft_swap_b(s_push);
}
