/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:04:29 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:00:08 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_list **a, char **input)
{
	int		n;
	int		i;

	i = 0;
	while (input[i])
	{
		if (split_and_format(a, input[i]))
			i++;
		if (!input[i])
			break ;
		n = format_num(a, input[i]);
		append_node(a, n);
		i++;
	}
}

int	split_and_format(t_list **a, char *input)
{
	char	**str;
	int		i;
	int		n;

	if (input && check_digit(input) > 1)
	{
		str = ft_split(input, ' ');
		i = 0;
		while (str[i])
		{
			n = format_num(a, str[i]);
			append_node(a, n);
			i++;
		}
		free_splitted(str);
		return (1);
	}
	return (0);
}

int	format_num(t_list **a, char *num)
{
	long	n;

	if (!check_digit(num))
		handle_error_and_free(a);
	n = ft_atol(num);
	if (!check_overflow(n))
		handle_error_and_free(a);
	if (!check_unique(*a, (int)n))
		handle_error_and_free(a);
	return ((int)n);
}

long	ft_atol(const char *str)
{
	int		sn;
	long	r;
	int		i;

	sn = 1;
	r = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * (long)sn);
}
