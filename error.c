/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:34:31 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/20 15:00:52 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_argv(int argc, char **argv, t_push *s_push)
{
	int	i;
	int	j;

	i = 0;
	s_push->len_a = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-')
				j++;
			else if (ft_isdigit(argv[i][j]) == 0)
			{
				if (argc == 2)
					ft_free_argv(argv);
				ft_error(ERROR, s_push);
			}
		}
		s_push->len_a++;
	}
}

void	ft_check_doublons(int argc, char **argv, t_push *s_push)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_push->len_a)
	{
		j = 0;
		while (j < s_push->len_a)
		{
			if (s_push->a[i] == s_push->a[j] && i != j)
			{
				if (argc == 2)
					ft_free_argv(argv);
				ft_error(DOUBLE, s_push);
			}
			j++;
		}
		i++;
	}
}

void	ft_error(char *str, t_push *s_push)
{
	if (s_push->a)
		free(s_push->a);
	if (s_push->b)
		free(s_push->b);
	free(s_push);
	ft_printf("\033[1;41m%s\033[00m", str);
	exit (0);
}
