/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:49:26 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 13:58:54 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
}

void	append_node(t_list **stack, int n)
{
	t_list	*node;
	int		*nbr;

	nbr = (int *)malloc(2 * sizeof(int));
	if (!nbr)
		handle_error_and_free(stack);
	nbr[0] = n;
	nbr[1] = -1;
	node = ft_lstnew(nbr);
	ft_lstadd_back(stack, node);
}

int	is_sorted(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node && node->next)
	{
		if (*(int *)(node->content) > *(int *)(node->next->content))
			return (0);
		node = node->next;
	}
	return (1);
}

int	is_sorted_desc(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node && node->next)
	{
		if (*(int *)(node->content) < *(int *)(node->next->content))
			return (0);
		node = node->next;
	}
	return (1);
}
