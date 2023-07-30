/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 04:16:37 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/30 04:26:31 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_operator(t_list **stack_a, t_list **stack_b, int operator_number, int number_position, int min_or_max)
{
	printf("El stack_a es: ");
	printLinkedList(*stack_a);
	printf("El stack_b es: ");
	printLinkedList(*stack_b);
	printf("EL NÚMERO A MOVER ES %d\n", operator_number);
	if (min_or_max == 0)
	{
		printf("Es máximo o mínimo\n");
		printf("El stack_a es: ");
		printLinkedList(*stack_a);
		printf("El stack_b es: ");
		printLinkedList(*stack_b);
		move_max_num_on_top(stack_b, ft_lstsize(*stack_b));
		move_number(stack_a, stack_b, number_position, "move_operator");
		printf("DESPUÉS DEL MOVE NUMBER\n");
		printf("El stack_a es: ");
		printLinkedList(*stack_a);
		printf("El stack_b es: ");
		printLinkedList(*stack_b);
		return ;
	}
	else
	{
		printf("El número %d no es máximo o mínimo en el stack_b\n", operator_number);
		move_middle_number(stack_a, stack_b, operator_number, number_position);
		printLinkedList(*stack_b);
		move_number(stack_a, stack_b, number_position, "move_operator");
		printLinkedList(*stack_a);
		printLinkedList(*stack_b);
		printf("SALE DEL MOVE\n\n\n\n\n");
		return ;
	}
}

void	move_middle_number(t_list **stack_a, t_list **stack_b, int operator_number, int number_position)
{
	int	just_smaller_number;
	int	just_smaller_number_position;
	int	node_number;
	t_list *stack_b_first_nb;

	just_smaller_number = 0;
	just_smaller_number_position = 0;
	node_number = 0;
	stack_b_first_nb = *stack_b;
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
	*stack_b = stack_b_first_nb;
	printf("JUST SMALLER NUMBER: %d, ITS POSITION: %d\n", just_smaller_number, just_smaller_number_position);
	if (just_smaller_number_position > ft_lstsize(*stack_b)/2)
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
	/* printf("El stack_a es: ");
	printLinkedList(*stack_a);
	printf("El stack_b es: ");
	printLinkedList(*stack_b);
	exit(0); */
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

void	move_number(t_list **stack_a, t_list **stack_b, int number_position, char *caller)
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
	if (ft_strcmp(caller, "push_a_checker") == 0)
		return ;
	push_b(stack_a, stack_b);	
}
