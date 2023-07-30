/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/30 04:43:40 by drestrep         ###   ########.fr       */
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

int     check_if_min_or_max(t_list **stack, int stack_a_number)
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

	printf("STACK SIZE: %d\n", size);
	printf("POSITION: %d\n", position);
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
	return (just_smaller_number_position);
}

void push_a_checker(t_list **stack_a, t_list **stack_b)
{
	int		just_bigger_number;
	int		just_bigger_number_position;
	int		current_position;
	t_list	*stack_a_first_nb;

		printf("El stack_a es: ");
	printLinkedList(*stack_a);
	printf("El stack_b es: ");
	printLinkedList(*stack_b);

	just_bigger_number = *(int *)(*stack_a)->content;
	just_bigger_number_position = 0;
	current_position = 0;
	stack_a_first_nb = *stack_a;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content > just_bigger_number)
		{
			just_bigger_number = *(int *)(*stack_a)->content;
			just_bigger_number_position = current_position;
		}
		current_position++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = stack_a_first_nb;
	if (just_bigger_number != 0)
		move_number(stack_a, stack_b, just_bigger_number_position, "push_a_checker");
	printf("El stack_a es: ");
	printLinkedList(*stack_a);
	printf("El stack_b es: ");
	printLinkedList(*stack_b);
	exit(0);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	three_numbers(stack_a);
	move_max_num_on_top(stack_b, ft_lstsize(*stack_b));
	while (*stack_b)
	{
		push_a_checker(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	printLinkedList(*stack_a);
	printLinkedList(*stack_b);
	exit(0);
}

void    sort_big(t_list **stack_a, t_list **stack_b, int argc)
{
	argc = 0;

	int position;
	int min_or_max;
	int total_operations = 0;
	int minimum_operations;
	int	operator_number;
	int	operator_position;
	t_list  *stack_a_first_nb;
	//t_list  *stack_b_first_nb;

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
			printf("El stack_a es: ");
			printLinkedList(stack_a_first_nb);
			printf("El número a comparar del stack_a es: %d\n", operator_number);
			printf("El stack_b es: ");
			printLinkedList(*stack_b);
			min_or_max = check_if_min_or_max(stack_b, operator_number);
			if (min_or_max == 0)
			{
				printf("ES MIN O MAX\n");
				printf("La posición del %d en el stack_a es: %d\n", operator_number, position);
				total_operations = max_num_on_top(stack_b, ft_lstsize(*stack_b)) + max_or_min_number(position, ft_lstsize(stack_a_first_nb)) + 1;
				int max_num_on_top_x = max_num_on_top(stack_b, ft_lstsize(*stack_b));
				int max_or_min_number_x = max_or_min_number(position, ft_lstsize(stack_a_first_nb));
				printf("MAX_NUM_ON_TOP_RESULT: %d\nMAX OR MIN NUMBER RESULT: %d\n", max_num_on_top_x, max_or_min_number_x);
				if (minimum_operations == 0)
				if (minimum_operations == 0)
					minimum_operations = total_operations;
				if (total_operations < minimum_operations)
				{
					minimum_operations = total_operations;
					operator_position = position;
				}
			}
			else
			{
				printf("NO ES MIN O MAX\n");
				printf("La posición del %d en el stack_a es: %d\n", operator_number, position);
				total_operations = middle_number(stack_b, operator_number, ft_lstsize(*stack_b)) + max_or_min_number(position, ft_lstsize(stack_a_first_nb)) + 1;
				int middle_number_x = middle_number(stack_b, operator_number, ft_lstsize(*stack_b));
				int max_or_min_number_x = max_or_min_number(position, ft_lstsize(stack_a_first_nb));
				printf("MIDDLE NUMBER RESULT: %d\nMAX OR MIN NUMBER RESULT: %d\n", middle_number_x, max_or_min_number_x);
				if (minimum_operations == 0)
					minimum_operations = total_operations;
				if (total_operations < minimum_operations)
				{
					minimum_operations = total_operations;
					operator_position = position;
				}
			}
			//int total_operations_for_this_number = total_operations;
			printf("LAS OPERACIONES NECESARIAS PARA MOVER EL %d SON: %d\n", operator_number, total_operations);
			printf("EL MÍNIMO DE OPERACIONES NECESARIAS PARA CUALQUIER NÚMERO SON: %d\n\n\n",minimum_operations);
			*stack_a = (*stack_a)->next;
			position++;
		}
		*stack_a = stack_a_first_nb;
		operator_number = *(int *)(stack_a_first_nb)->content;
		min_or_max = check_if_min_or_max(stack_b, operator_number);
		move_operator(stack_a, stack_b, operator_number, operator_position, min_or_max);
	}
	push_back(stack_a, stack_b);
}