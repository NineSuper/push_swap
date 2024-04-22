/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:16:46 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/15 18:48:52 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_b(t_push *s_push)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	temp = malloc(sizeof(int) * (s_push->len_b));
	while (i < s_push->len_b)
		temp[i++] = s_push->b[j++];
	free(s_push->b);
	s_push->b = temp;
}

void	ft_malloc_a(int new, t_push *s_push)
{
	int	*temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	s_push->len_a++;
	s_push->len_b--;
	temp = malloc(sizeof(int) * (s_push->len_a + 1));
	temp[0] = new;
	while (i < s_push->len_a)
		temp[i++] = s_push->a[j++];
	free(s_push->a);
	s_push->a = temp;
	ft_new_b(s_push);
}

void	ft_push_a(t_push *s_push)
{
	int	temp;

	if (!s_push->len_b)
		return ;
	temp = s_push->b[0];
	ft_malloc_a(temp, s_push);
	ft_printf("pa\n");
}
