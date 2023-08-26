/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:16:32 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/26 21:29:29 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int check_all_doubles (t_list **stack_a, t_list **stack_b)
{
	int	result;
	if (SOLO HAY RR O RRR)
		result = 0;
	else
		result = 1;
	return (result);
}

int	ft_exception (t_list **stack_a, t_list **stack_b, char c)
{
	int number;
	int node_number;
	int	position;
	int	all_doubles;
	int	min_or_max;
	t_list *stack_a_first_nb;

	node_number = 0;
	min_or_max = check_if_min_or_max(stack_a, (*stack_a)->content);
	stack_a_first_nb = *stack_a;
	while (*stack_a)
	{
		all_doubles = check_all_doubles(stack_a, stack_b);
		if (all_doubles == 0)
		{
			number = (*stack_a)->content;
			position = node_number;
		}
		node_number++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = stack_a_first_nb;
	if (c == 'n')
		return (number);
	if (c == 'p')
		return (position);
}