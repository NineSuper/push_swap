/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:47:41 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/15 18:49:26 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_a(t_push *s_push)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	temp = malloc(sizeof(int) * (s_push->len_a));
	while (i < s_push->len_a)
		temp[i++] = s_push->a[j++];
	free(s_push->a);
	s_push->a = temp;
}

void	ft_malloc_b(int new, t_push *s_push)
{
	int	*temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	s_push->len_b++;
	s_push->len_a--;
	temp = malloc(sizeof(int) * (s_push->len_b + 1));
	temp[0] = new;
	while (i < s_push->len_b)
		temp[i++] = s_push->b[j++];
	free(s_push->b);
	s_push->b = temp;
	ft_new_a(s_push);
}

void	ft_push_b(t_push *s_push)
{
	int	temp;

	if (!s_push->len_a)
		return ;
	temp = s_push->a[0];
	ft_malloc_b(temp, s_push);
	ft_printf("pb\n");
}
