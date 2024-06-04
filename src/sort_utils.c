/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:26 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:17:26 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min(t_list **stack)
{
	t_list	*node;
	t_list	*min_node;

	if (!stack)
		return (NULL);
	node = *stack;
	min_node = node;
	while (node)
	{
		if (*(int *)(node->content) < *(int *)(min_node->content))
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

t_list	*get_max(t_list **stack)
{
	t_list	*node;
	t_list	*max_node;

	if (!stack)
		return (NULL);
	node = *stack;
	max_node = node;
	while (node)
	{
		if (*(int *)(node->content) > *(int *)(max_node->content))
			max_node = node;
		node = node->next;
	}
	return (max_node);
}

int	get_pos(t_list **stack, t_list *target)
{
	t_list	*node;
	int		pos;

	node = *stack;
	pos = 0;
	while (node)
	{
		if (node == target)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

int	find_pos_b(t_list **b, int n)
{
	int		pos;
	t_list	*node;

	if (!*b)
		return (0);
	pos = 1;
	node = *b;
	if (n > *(int *)(node->content) && n < *(int *)(ft_lstlast(*b)->content))
		pos = 0;
	else if (n > *(int *)(get_max(b)->content)
			|| n < *(int *)(get_min(b)->content))
		pos = get_pos(b, get_max(b));
	else
	{
		while (*(int *)(node->content) < n || *(int *)(node->next->content) > n)
		{
			node = node->next;
			pos++;
		}
	}
	return (pos);
}

int	find_pos_a(t_list **a, int n)
{
	int		pos;
	t_list	*node;

	if (!*a)
		return (0);
	pos = 1;
	node = *a;
	if (n < *(int *)(node->content) && n > *(int *)(ft_lstlast(*a)->content))
		pos = 0;
	else if (n > *(int *)(get_max(a)->content)
			|| n < *(int *)(get_min(a)->content))
		pos = get_pos(a, get_min(a));
	else
	{
		while (*(int *)(node->content) > n || *(int *)(node->next->content) < n)
		{
			node = node->next;
			pos++;
		}
	}
	return (pos);
}
