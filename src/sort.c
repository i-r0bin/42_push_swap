/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:21:08 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:02:04 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a) || size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_many(stack_a, stack_b);
}

void	sort_three(t_list **a)
{
	t_list	*max_node;

	if (is_sorted(a))
		return ;
	max_node = get_max(a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
		sa(a);
}

void	sort_many(t_list **a, t_list **b)
{
	t_list	*target;

	target = NULL;
	while (ft_lstsize(*a) > 3 && !is_sorted(a))
	{
		target = set_target(a, b, get_moves_ab);
		push_target_ab(a, b, target);
	}
	if (!is_sorted(a))
		sort_three(a);
	while (*b)
	{
		target = set_target(a, b, get_moves_ba);
		push_target_ba(a, b, target);
	}
	target = get_min(a);
	set_top_node(a, target);
}

t_list	*set_target(t_list **a, t_list **b,
		int get_moves(t_list **a, t_list **b, t_list *node, int *code))
{
	t_list	*node;
	t_list	*target;
	int		moves;
	int		code;
	int		tmp;

	if (get_moves == get_moves_ba)
		node = *b;
	else
		node = *a;
	code = -1;
	tmp = -2;
	moves = INT_MAX;
	while (node)
	{
		if (node == *a || get_moves(a, b, node, &tmp) < moves)
		{
			moves = get_moves(a, b, node, &code);
			target = node;
		}
		node = node->next;
	}
	*(int *)(target->content + 4) = code;
	return (target);
}

void	set_top_node(t_list **stack, t_list *target)
{
	int	pos;

	pos = get_pos(stack, target);
	if (pos < ft_lstsize(*stack) - pos)
	{
		while (*stack != target)
			ra(stack);
	}
	else
	{
		while (*stack != target)
			rra(stack);
	}
}
