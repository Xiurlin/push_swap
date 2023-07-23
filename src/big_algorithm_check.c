/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/21 05:41:49 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    max_num_on_top(t_list **stack, int size)
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

int     check_if_min_or_max(int stack_a_number, t_list **stack)
{
    int     stack_b_max;
    int     stack_b_min;
    t_list  *aux;

    stack_b_min = *(int *)(*stack)->content;
    stack_b_max = *(int *)(*stack)->content;
    aux = *stack;
    while (*stack)
    {
        if (*(int *)(*stack)->content > stack_b_max)
            stack_b_max = *(int *)(*stack)->content;
        if (*(int *)(*stack)->content < stack_b_min)
            stack_b_min = *(int *)(*stack)->content;
        *stack = (*stack)->next;
    }
    *stack = aux;
    if (stack_a_number < stack_b_min || stack_a_number > stack_b_max)
        return(0);
    return(1);
}

int max_or_min_number(int position, int size)
{
    int operations;

    if (position > size/2)
        operations = size - position;
    else
        operations = position;
    return(operations);
}

int     middle_number(t_list **stack, int number, int size)
{
    int node_number;
    int just_smaller_number;
    int just_smaller_number_position;
    t_list  *aux;

    aux = *stack;
    node_number = 0;
    just_smaller_number = 0;
    just_smaller_number_position = 0;
    while (*stack)
    {
        if (just_smaller_number == 0 && *(int *)(*stack)->content < number)
        {
            just_smaller_number = *(int *)(*stack)->content;
            just_smaller_number_position = node_number;
        }
        if (*(int *)(*stack)->content < number && *(int *)(*stack)->content > just_smaller_number)
        {
            just_smaller_number = *(int *)(*stack)->content;
            just_smaller_number_position = node_number;
        }
        *stack = (*stack)->next;
        node_number++;
    }
	*stack = aux;
    if (just_smaller_number_position > size/2)
    	just_smaller_number_position = size - just_smaller_number_position;
    return (just_smaller_number);
}

void    sort_big(t_list **stack_a, t_list **stack_b, int argc)
{
    int position;
    int min_or_max;
    int total_operations = 0;
    int minimum_operations;
	int	operator_number;
	int	operator_position;
    t_list  *aux;

    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    position = 0;
	operator_position = 0;
    minimum_operations = max_num_on_top(stack_b, argc) + 1;
	while (*stack_a)
	{
    	aux = *stack_a;
		while (*stack_a)
		{
			min_or_max = check_if_min_or_max(*(int *)(*stack_a)->content, stack_b);
			if (min_or_max == 0)
			{
				total_operations = max_num_on_top(stack_b, argc) + max_or_min_number(position, argc);
				if (total_operations < minimum_operations)
				{
					minimum_operations = total_operations;
					operator_number	= *(int *)(*stack_a)->content;
					operator_position = position;
				}
			}
			else
			{
				total_operations = middle_number(stack_b, *(int *)(*stack_a)->content, argc);
				*stack_a = (*stack_a)->next;
				if (total_operations < minimum_operations)
				{
					minimum_operations = total_operations;
					operator_number	= *(int *)(*stack_a)->content;
					operator_position = position;
				}
			}
			printf("%d\n", min_or_max);
			*stack_a = (*stack_a)->next;
			position++;
		}
		*stack_a = aux;
		min_or_max = check_if_min_or_max(operator_number, stack_b);
		move_operator(operator_number, operator_position, min_or_max, argc, stack_a, stack_b);
		*stack_a = (*stack_a)->next;
	}
    exit(0);
}
