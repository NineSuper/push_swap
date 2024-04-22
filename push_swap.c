/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:09:40 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/20 15:08:47 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_push *s_push)
{
	int	i;

	i = 0;
	while (i < s_push->len_a || i < s_push->len_b)
	{
		if (i >= s_push->len_a)
			ft_printf(" \t|\t%d\n", s_push->b[i]);
		else if (i >= s_push->len_b)
			ft_printf("%d\t|\t \n", s_push->a[i]);
		else
			ft_printf("%d\t|\t%d\n", s_push->a[i], s_push->b[i]);
		i++;
	}
	ft_printf("-----------------------\n   A\t|\tB\n");
}

int	ps_strstr(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s2)
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_list_a(int argc, char **argv, t_push *s_push)
{
	char	*test;
	int		i;

	i = 0;
	s_push->a = ft_calloc(1, sizeof(int) * s_push->len_a + 1);
	while (argv[i + 1] != NULL)
	{
		s_push->a[i] = ft_atoi(argv[i + 1]);
		test = ft_itoa(s_push->a[i]);
		if (ps_strstr(test, argv[i + 1]) == 0)
		{
			free(test);
			if (argc == 2)
				ft_free_argv(argv);
			ft_error(ERROR, s_push);
		}
		if (test)
			free(test);
		i++;
	}
	ft_check_doublons(argc, argv, s_push);
}

int	main(int argc, char **argv)
{
	t_push		*s_push;
	char		*str;

	s_push = ft_calloc(1, sizeof(t_push));
	if (argc < 2)
		ft_error("", s_push);
	if (argc == 2)
	{
		str = ft_strjoin("./push_swap ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
	}
	ft_check_argv(argc, argv, s_push);
	ft_list_a(argc, argv, s_push);
	if (argc == 2)
		ft_free_argv(argv);
	if (s_push->len_a < 2)
		ft_error("", s_push);
	s_push->b = ft_calloc(1, sizeof(int) * s_push->len_a);
	ft_algo(s_push);
	if (s_push->a)
		free(s_push->a);
	if (s_push->b)
		free(s_push->b);
	free(s_push);
}
