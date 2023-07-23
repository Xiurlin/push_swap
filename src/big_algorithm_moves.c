/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 04:16:37 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/21 05:42:35 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_operator(int operator_number, int number_position, int min_or_max, int size, t_list **stack_a, t_list **stack_b)
{
	if (min_or_max == 0)
	{
		move_max_num_on_top(stack_b, size);
		move_number(number_position, stack_a, stack_b);
		printLinkedList(*stack_b);
		return ;
	}
	else
	{
		move_middle_number(operator_number, number_position, stack_a, stack_b);
		move_number(number_position, stack_a, stack_a);
		printLinkedList(*stack_b);
		return ;
	}
}

void	move_middle_number(int operator_number, int number_position, t_list **stack_a, t_list **stack_b)
{
	int	just_smaller_number;
	int	just_smaller_number_position;
	int	node_number;

	just_smaller_number = 0;
	just_smaller_number_position = 0;
	node_number = 0;
	while (*stack_b)
	{
		if (just_smaller_number == 0 && *(int *)(*stack_b)->content < operator_number)
		{
			just_smaller_number = *(int *)(*stack_b)->content;
			just_smaller_number_position = node_number;
		}
		if (*(int *)(*stack_b)->content < operator_number && *(int *)(*stack_b)->content > just_smaller_number)
        {
            just_smaller_number = *(int *)(*stack_b)->content;
            just_smaller_number_position = node_number;
        }
		*stack_b = (*stack_b)->next;
		node_number++;
	}
	if (just_smaller_number > ft_lstsize(*stack_b)/2)
	{
		while (just_smaller_number_position < ft_lstsize(*stack_b))
		{
			revrotate_b(stack_b);
			just_smaller_number_position++;
		}
	}
	else
	{
		while (just_smaller_number_position > 0)
		{
			rotate_b(stack_b);
			just_smaller_number_position--;
		}
	}
	if (number_position > ft_lstsize(*stack_a)/2)
	{
		while (number_position < ft_lstsize(*stack_a))
		{
			revrotate_a(stack_a);
			number_position++;
		}
	}
	else
	{
		while (number_position > 0)
		{
			rotate_b(stack_a);
			just_smaller_number_position--;
		}
	}
}

void    move_max_num_on_top(t_list **stack, int size)
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
	{
		max_number_position = size - max_number_position;
		while (max_number_position < size)
		{
			revrotate_b(stack);
			max_number_position++;
		}
	}
	else
	{
		while (max_number_position > 0)
		{
			rotate_b(stack);
			max_number_position--;
		}
	}
}

void	move_number(int number_position, t_list **stack_a, t_list **stack_b)
{
	if (number_position > ft_lstsize(*stack_a)/2)
	{
		while(number_position < ft_lstsize(*stack_a))
		{
			revrotate_a(stack_a);
			number_position++;
		}
	}
	else
	{
		while (number_position > 0)
		{
			rotate_a(stack_a);
			number_position--;
		}
	}	
	push_b(stack_a, stack_b);	
}
