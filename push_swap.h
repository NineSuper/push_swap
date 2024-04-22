/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:04:34 by tde-los-          #+#    #+#             */
/*   Updated: 2023/04/20 15:00:40 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h" 
# include "libft/gnl/get_next_line.h" 
# include "libft/ft_printf/ft_printf.h" 
/*		MESSAGE			*/
# define ERROR "Error\n"
# define DOUBLE "Error : doublons\n"

typedef struct s_push
{
	int	*a;
	int	*b;
	int	*c;
	int	len_a;
	int	len_b;
	int	rr;
}	t_push;

int		isgood(int *array, t_push *s_push);
void	ft_error(char *str, t_push *s_push);
void	ft_check_doublons(int argc, char **argv, t_push *s_push);
void	ft_check_argv(int argc, char **argv, t_push *s_push);
void	ft_swap_a(t_push *s_push);
void	ft_swap_b(t_push *s_push);
void	ft_swap_ss(t_push *s_push);
void	ft_push_a(t_push *s_push);
void	ft_push_b(t_push *s_push);
void	ft_rotate_a(t_push *s_push);
void	ft_rotate_b(t_push *s_push);
void	ft_rotate_ab(t_push *s_push);
void	ft_reverse_ab(t_push *s_push);
void	ft_reverse_a(t_push *s_push);
void	ft_reverse_b(t_push *s_push);
void	ft_algo(t_push *s_push);
void	ft_algo_for_three(t_push *s_push);
void	ft_big_algo(t_push *s_push, int i, int j);
void	checkmax(int *array, int n, t_push *s_push);
void	ft_list_a(int argc, char **argv, t_push *s_push);
void	ft_free_argv(char **argv);

#endif
