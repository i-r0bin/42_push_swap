/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:30:47 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 13:38:46 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

void	init_data(t_list **a, char **input);
int		split_and_format(t_list **a, char *input);
int		format_num(t_list **a, char *num);
long	ft_atol(const char *str);

int		check_digit(char *str);
int		check_overflow(long n);
int		check_unique(t_list *a, int n);
void	free_splitted(char **splitted);

void	append_node(t_list **stack, int n);
int		is_sorted(t_list **stack);
int		is_sorted_desc(t_list **stack);
void	free_stack(t_list **stack);

void	handle_error_and_free(t_list **a);
void	handle_error(void);

void	sort(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **a);
void	sort_many(t_list **a, t_list **b);
t_list	*set_target(t_list **a, t_list **b,
			int get_moves(t_list **a, t_list **b, t_list *node, int *code));
void	set_top_node(t_list **a, t_list *target);

t_list	*get_max(t_list **stack);
t_list	*get_min(t_list **stack);
int		get_pos(t_list **stack, t_list *target);
int		find_pos_b(t_list **b, int n);
int		find_pos_a(t_list **a, int n);

int		get_moves_ab(t_list **a, t_list **b, t_list *target, int *code);
void	push_target_ab(t_list **a, t_list **b, t_list *target);
void	exec_rr_ab(t_list **a, t_list **b, t_list *target);
void	exec_rrr_ab(t_list **a, t_list **b, t_list *target);
void	exec_rrarb_ab(t_list **a, t_list **b, t_list *target);
void	exec_rarrb_ab(t_list **a, t_list **b, t_list *target);

int		get_moves_ba(t_list **a, t_list **b, t_list *target, int *code);
void	push_target_ba(t_list **a, t_list **b, t_list *target);
void	exec_rr_ba(t_list **a, t_list **b, t_list *target);
void	exec_rrr_ba(t_list **a, t_list **b, t_list *target);
void	exec_rrarb_ba(t_list **a, t_list **b, t_list *target);
void	exec_rarrb_ba(t_list **a, t_list **b, t_list *target);

void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
