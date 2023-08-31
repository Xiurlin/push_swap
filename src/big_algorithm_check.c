/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/31 02:35:12 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_num_on_top(t_list **stack, int size)
{
	int     max_number;
	int     max_number_position;
	int     node_number;

	t_list *aux = *stack;

	max_number = *(int *)(*stack)->content;
	max_number_position = 0;
	node_number = 0;
	while (*stack)
	{
		if (*(int *)(*stack)->content > max_number)
		{
			max_number = *(int *)(*stack)->content;
			max_number_position = node_number;
		}
		*stack = (*stack)->next;
		node_number++;
	}
	*stack = aux;
	if (max_number_position > size/2)
		max_number_position = size - max_number_position;
	return(max_number_position);
}

int	get_double_rotate(t_list *stack_a, t_list *stack_b, int operator_position, int stack_b_number_position, int total_operations)
{
	int	operations;

	operations = 0;
	if (operator_position == 0 || stack_b_number_position == 0)
		return (total_operations);
	if (operator_position > ft_lstsize(stack_a)/2 && stack_b_number_position > ft_lstsize(stack_b)/2)
	{
		if (ft_lstsize(stack_a) - operator_position < ft_lstsize(stack_b) - stack_b_number_position)
		{
			operations = ft_lstsize(stack_a) - operator_position;
			operations = operations + ft_lstsize(stack_b) - stack_b_number_position - operations + 1;
		}
		else if (ft_lstsize(stack_b) - stack_b_number_position < ft_lstsize(stack_a) - operator_position)
		{
			operations = ft_lstsize(stack_b) - stack_b_number_position;
			operations = operations + ft_lstsize(stack_a) - operator_position - operations + 1;
		}
	}
	else if (operator_position <= ft_lstsize(stack_a)/2 && stack_b_number_position <= ft_lstsize(stack_b)/2)
	{
		operations = operator_position + 1;
		if (operator_position < stack_b_number_position)
			operations = operator_position + (stack_b_number_position - operator_position) + 1;
		if (stack_b_number_position < operator_position)
			operations = stack_b_number_position + (operator_position - stack_b_number_position) + 1;
	}
	if (operations < total_operations && operations != 0)
		total_operations = operations;
	return (total_operations);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int position;
	int min_or_max;
	int total_operations = 0;
	int minimum_operations;
	int	operator_number;
	int	operator_position;
	t_list  *stack_a_first_nb;
	
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		operator_position = 0;
		minimum_operations = 0;
		position = 0;
		stack_a_first_nb = *stack_a;
		while (*stack_a)
		{
			operator_number	= *(int *)(*stack_a)->content;
			min_or_max = check_if_min_or_max(stack_b, operator_number);
			if (min_or_max == 0)
			{
				total_operations = max_num_on_top(stack_b, ft_lstsize(*stack_b)) + max_or_min_number(position, ft_lstsize(stack_a_first_nb)) + 1;
				total_operations = get_double_rotate(stack_a_first_nb, *stack_b, position, get_max_number_position(stack_b), total_operations);
				if (minimum_operations == 0)
					minimum_operations = total_operations;
				if (total_operations < minimum_operations)
				{
					operator_number = *(int *)(*stack_a)->content;
					operator_position = position;
					minimum_operations = total_operations;
				}
			}
			else
			{
				total_operations = middle_number(stack_b, operator_number, ft_lstsize(*stack_b)) + max_or_min_number(position, ft_lstsize(stack_a_first_nb)) + 1;
				total_operations = get_double_rotate(stack_a_first_nb, *stack_b, position, get_smaller_number_position(stack_b, operator_number, 0, 0), total_operations);
				if (minimum_operations == 0)
					minimum_operations = total_operations;
				if (total_operations < minimum_operations)
				{
					minimum_operations = total_operations;
					operator_position = position;
					operator_number = *(int *)(*stack_a)->content;
				}
			}
			*stack_a = (*stack_a)->next;
			position++;
		}
		*stack_a = stack_a_first_nb;
		position = 0;
		while (position < operator_position)
		{
			*stack_a = (*stack_a)->next;
			position++;
		}
		operator_number = *(int *)(*stack_a)->content;
		*stack_a = stack_a_first_nb;
		min_or_max = check_if_min_or_max(stack_b, operator_number);
		move_operator(stack_a, stack_b, operator_number, operator_position, min_or_max);
	}
	push_back(stack_a, stack_b);
}
