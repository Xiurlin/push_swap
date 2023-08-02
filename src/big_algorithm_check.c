/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/02 14:52:15 by drestrep         ###   ########.fr       */
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

	//printf("STACK SIZE: %d\n", size);
	//printf("POSITION: %d\n", position);
	if (position > size/2)
		operations = size - position;
	else
		operations = position;
	return(operations);
}

int     middle_number(t_list **stack, int number, int size)
{
	int node_number;
	int next_smaller_number;
	int next_smaller_number_position;
	t_list  *aux;

	aux = *stack;
	node_number = 0;
	next_smaller_number = 0;
	next_smaller_number_position = 0;
	while (*stack)
	{
		if (next_smaller_number == 0 && *(int *)(*stack)->content < number)
		{
			next_smaller_number = *(int *)(*stack)->content;
			next_smaller_number_position = node_number;
		}
		if (*(int *)(*stack)->content < number && *(int *)(*stack)->content > next_smaller_number)
		{
			next_smaller_number = *(int *)(*stack)->content;
			next_smaller_number_position = node_number;
		}
		*stack = (*stack)->next;
		node_number++;
	}
	*stack = aux;
	if (next_smaller_number_position > size/2)
		next_smaller_number_position = size - next_smaller_number_position;
	return (next_smaller_number_position);
}

void push_a_checker(t_list **stack_a, t_list **stack_b)
{
	int		next_bigger_number;
	int		next_bigger_number_position;
	int		current_position;
	t_list	*stack_a_first_nb;

	//printf("El stack_a es: ");
	//printLinkedList(*stack_a);
	//printf("El stack_b es: ");
	//printLinkedList(*stack_b);

	next_bigger_number_position = -1;
	current_position = 0;
	stack_a_first_nb = *stack_a;
	while (*stack_a)
	{
		//printf("Next bigger number position: %d\n", next_bigger_number_position);
		if (next_bigger_number == 0 && *(int *)(*stack_a)->content > *(int *)(*stack_b)->content)
		{
			next_bigger_number = *(int *)(*stack_a)->content;
			next_bigger_number_position = current_position;
		}
		if (*(int *)(*stack_a)->content > *(int *)(*stack_b)->content && *(int *)(*stack_a)->content < next_bigger_number)
		{
			next_bigger_number = *(int *)(*stack_a)->content;
			next_bigger_number_position = current_position;
		}
		*stack_a = (*stack_a)->next;
		current_position++;
	}
	*stack_a = stack_a_first_nb;
	//printf("SALE\n");
	//printf("Next bigger number position: %d\n", next_bigger_number_position);
	if (next_bigger_number_position == -1)
	{
		//printf("ENTRAAAAAA\n");
		push_a(stack_a, stack_b);
		//printf("El stack_a es: ");
		//printLinkedList(*stack_a);
		//printf("El stack_b es: ");
		//printLinkedList(*stack_b);
		//printf("LLEGA HASTA AQUÍ?\n");
		return ;
	}
	order_stack(stack_a, next_bigger_number_position);
	//printf("El stack_a es: ");
	//printLinkedList(*stack_a);
	//printf("El stack_b es: ");
	//printLinkedList(*stack_b);
}

int	get_smallest_number_position(t_list **stack_a)
{
	t_list	*stack_a_first_nb;
	int	smallest_number;
	int	smallest_number_position;
	int	current_position;

	stack_a_first_nb = *stack_a;
	smallest_number = *(int *)(*stack_a)->content;
	current_position = 0;
	smallest_number_position = current_position;
	while (*stack_a)
	{
		//printf("The smallest number position is: %d\n", smallest_number_position);
		if (*(int *)(*stack_a)->content < smallest_number)
		{
			smallest_number = *(int *)(*stack_a)->content;
			smallest_number_position = current_position;
		}
		current_position++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = stack_a_first_nb;
	return (smallest_number_position);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	int		smallest_number_position;

	three_numbers(stack_a);
	move_max_num_on_top(stack_b, ft_lstsize(*stack_b));
	while (*stack_b)
	{
		push_a_checker(stack_a, stack_b);
		push_a(stack_a, stack_b);
		if (!*stack_b)
			break;
		*stack_b = (*stack_b)->next;
	}
	//printLinkedList(*stack_a);
	//printLinkedList(*stack_b);
	smallest_number_position = get_smallest_number_position(stack_a);
	order_stack(stack_a, smallest_number_position);
	//printf("El stack_a ordenado es: ");
	//printLinkedList(*stack_a);
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

	//printf("before\n");
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	//printf("after\n");
	while (ft_lstsize(*stack_a) > 3)
	{
		printf("here\n");
		operator_position = 0;
		minimum_operations = 0;
		position = 0;
		stack_a_first_nb = *stack_a;
		while (*stack_a)
		{
			operator_number	= *(int *)(*stack_a)->content;
			//printf("El stack_a es: ");
			//printLinkedList(stack_a_first_nb);
			//printf("El número a comparar del stack_a es: %d\n", operator_number);
			//printf("El stack_b es: ");
			//printLinkedList(*stack_b);
			min_or_max = check_if_min_or_max(stack_b, operator_number);
			if (min_or_max == 0)
			{
				//printf("ES MIN O MAX\n");
				//printf("La posición del %d en el stack_a es: %d\n", operator_number, position);
				total_operations = max_num_on_top(stack_b, ft_lstsize(*stack_b)) + max_or_min_number(position, ft_lstsize(stack_a_first_nb)) + 1;
				//int max_num_on_top_x = max_num_on_top(stack_b, ft_lstsize(*stack_b));
				//int max_or_min_number_x = max_or_min_number(position, ft_lstsize(stack_a_first_nb));
				//printf("MAX_NUM_ON_TOP_RESULT: %d\nMAX OR MIN NUMBER RESULT: %d\n", max_num_on_top_x, max_or_min_number_x);
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
				//printf("NO ES MIN O MAX\n");
				//printf("La posición del %d en el stack_a es: %d\n", operator_number, position);
				total_operations = middle_number(stack_b, operator_number, ft_lstsize(*stack_b)) + max_or_min_number(position, ft_lstsize(stack_a_first_nb)) + 1;
				//int middle_number_x = middle_number(stack_b, operator_number, ft_lstsize(*stack_b));
				//int max_or_min_number_x = max_or_min_number(position, ft_lstsize(stack_a_first_nb));
				//printf("MIDDLE NUMBER RESULT: %d\nMAX OR MIN NUMBER RESULT: %d\n", middle_number_x, max_or_min_number_x);
				if (minimum_operations == 0)
					minimum_operations = total_operations;
				if (total_operations < minimum_operations)
				{
					minimum_operations = total_operations;
					operator_position = position;
				}
			}
			//int total_operations_for_this_number = total_operations;
			//printf("LAS OPERACIONES NECESARIAS PARA MOVER EL %d SON: %d\n", operator_number, total_operations);
			//printf("EL MÍNIMO DE OPERACIONES NECESARIAS PARA CUALQUIER NÚMERO SON: %d\n\n\n",minimum_operations);
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
