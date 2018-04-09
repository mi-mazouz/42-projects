/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:02:23 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 15:18:39 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct		s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_stc
{
	t_stack			*pa;
	t_stack			*pb;
	t_stack			*save;
	int				n;
	int				r;
	int				c;
	int				p;
	int				a;
	int				b;
	uintmax_t		nb_op;
}					t_stc;

int					ft_size_stack(t_stack *curs_a);
int					ft_flags(char *argv, t_stc *stc);
int					ft_check_argv(int argc, char **argv, t_stc *stc);
int					ft_str_size(char *str);
int					ft_check_double(t_stc *stc);
int					ft_check_sort(t_stack *curs_a);
int					ft_ra_ok(t_stack *stc_a, int number);
int					ft_special_k(t_stc *stc, t_stack **curs_a, t_stack *curs_b);

void				ft_special_k_2(t_stc *stc, t_stack *curs, t_stack **curs_a,
					t_stack *curs_b);
void				ft_swap_pa(t_stc *stc, t_stack **curs_a, t_stack *curs_b);
void				ft_push_all(t_stc *stc, t_stack **curs_a, t_stack **curs_b);
void				ft_push_min(t_stc *stc, t_stack **curs_a, t_stack **curs_b);
void				ft_check_min(t_stc *stc, t_stack **curs_a);
void				ft_rra_or_ra(t_stc *stc, t_stack **curs_a, t_stack *curs_b);
void				ft_rra_or_ra_2(t_stc *stc, t_stack **curs_a,
					t_stack *curs_b);
void				ft_print_stack(t_stc *stc, t_stack *stc_a, t_stack *stc_b);
void				ft_print_stack_2(t_stc *stc, t_stack *stc_a,
					t_stack *stc_b);
void				ft_free_list(t_stack **stc_a);
void				ft_make_list(t_stack **all, char *str);
void				ft_swap_a(t_stack **stc_a);
void				ft_push_a(t_stack **stc_a, t_stack **stc_b);
void				ft_push_b(t_stack **stc_a, t_stack **stc_b);
void				ft_rotate_a(t_stack **stc_a);
void				ft_init_stc(t_stc *stc, t_stack **curs_a, t_stack **cur_b);
void				ft_reverse_rotate_a(t_stack **stc_a);
void				ft_algo_sort(t_stc *stc, t_stack *curs_a, t_stack *curs_b);
void				ft_print_result(t_stc stc);

long				ft_atoi_l(char *str);

#endif
