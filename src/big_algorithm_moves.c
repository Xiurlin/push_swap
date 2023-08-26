/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 04:16:37 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/26 16:50:23 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	double_rotate(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position, int min_or_max)
{
	//t_list	*first_node;
	int		stack_b_operator_position;

	//first_node = *stack_a;
	//printf("Entra aquí?\n");
	//printf("Operator position: %d\n", operator_position);
			/* printf("El stack_a es: ");
			printLinkedList(*stack_a);
			printf("El stack_b es: ");
			printLinkedList(*stack_b);
			printf("Entra aquí??\n"); */
	if (min_or_max == 0)
		stack_b_operator_position = get_max_nb_position(stack_b);
	if (min_or_max == 1)
		stack_b_operator_position = get_middle_number_position(stack_b, operator_number);
	/* printf ("Stack_b operator position: %d\n", stack_b_operator_position);
	printf("\n\n\n\n\n\n\nEl stack_a es: ");
			printLinkedList(*stack_a);
			printf("El stack_b es: ");
			printLinkedList(*stack_b); */
	if (operator_position == 0 || stack_b_operator_position == 0)
		return (operator_position);
	if (operator_position > ft_lstsize(*stack_a)/2 && stack_b_operator_position > ft_lstsize(*stack_b)/2)
	{
		while (operator_position < ft_lstsize(*stack_a) && stack_b_operator_position < ft_lstsize(*stack_b))
		{
			revrotate(stack_a, stack_b);
			operator_position++;
			stack_b_operator_position++;
		}
	}
	else if (operator_position <= ft_lstsize(*stack_a)/2 && stack_b_operator_position <= ft_lstsize(*stack_b)/2)
	{
		//printf("\nOperator position: %d\nStack_b_operator_position: %d\n", operator_position, stack_b_operator_position);
		while (operator_position > 0 && stack_b_operator_position > 0)
		{
			rotate(stack_a, stack_b);
			operator_position--;
			stack_b_operator_position--;
		}/* 
		printf("El stack_a es: ");
		printLinkedList(*stack_a);
		printf("El stack_b es: ");
		printLinkedList(*stack_b); */
	}
	return (operator_position);
	//*stack_a = first_node;
}

void	move_operator(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position, int min_or_max)
{
	//SEGUIMOS AQUÍ
		/* printf("El stack_a  es: ");
		printLinkedList(*stack_a);
		printf("El stack_b  es: ");
		printLinkedList(*stack_b); */
	//double_rotate = check_double_rotate(stack_a, stack_b, operator_number, operator_position);
	if (min_or_max == 0)
	{
		//printf("Entraría aquí el %d?\n", operator_number);
		operator_position = double_rotate(stack_a, stack_b, operator_number, operator_position, min_or_max);
		/* printf("El stack_a después del move_operator es: ");
		printLinkedList(stack_a_first_nb);
		printf("El stack_b después del move_operator es: ");
		printLinkedList(*stack_b); */
		move_max_num_on_top(stack_b, ft_lstsize(*stack_b));
		//order_stack(stack_a, operator_position);
		push_b(stack_a, stack_b);
		return ;
	}
	else
	{
		//printf("Entra aquí?\n");
		operator_position = double_rotate(stack_a, stack_b, operator_number, operator_position, min_or_max);
		//printf("Ha hecho algo?\n");
		//printf("Operator positions: %d\n", operator_position);
		move_middle_number(stack_a, stack_b, operator_number, operator_position);
		//order_stack(stack_a, operator_position);
		push_b(stack_a, stack_b);
		return ;
	}
}

void	move_middle_number(t_list **stack_a, t_list **stack_b, int operator_number, int operator_position)
{
	int	just_smaller_number;
	int	just_smaller_operator_position;
	int	node_number;
	int	min_or_max;
	t_list *stack_b_first_nb;

	just_smaller_number = 0;
	just_smaller_operator_position = 0;
	node_number = 0;
	min_or_max = check_if_min_or_max (stack_a, operator_number);
	stack_b_first_nb = *stack_b;
	while (*stack_b)
	{
		if (just_smaller_number == 0 && *(int *)(*stack_b)->content < operator_number)
		{
			just_smaller_number = *(int *)(*stack_b)->content;
			just_smaller_operator_position = node_number;
		}
		if (*(int *)(*stack_b)->content < operator_number && *(int *)(*stack_b)->content > just_smaller_number)
		{
			just_smaller_number = *(int *)(*stack_b)->content;
			just_smaller_operator_position = node_number;
		}
		*stack_b = (*stack_b)->next;
		node_number++;
	}
	*stack_b = stack_b_first_nb;
	//printf("JUST SMALLER NUMBER: %d, ITS POSITION: %d\n", just_smaller_number, just_smaller_operator_position);
	//printf("Operator number: %d\nOperator position: %d\n", operator_number, operator_position);
	double_rotate(stack_a, stack_b, operator_number, operator_position, min_or_max);
	if (just_smaller_operator_position > ft_lstsize(*stack_b)/2)
	{
		while (just_smaller_operator_position < ft_lstsize(*stack_b))
		{
			revrotate_a_or_b(stack_b, 'b');
			just_smaller_operator_position++;
		}
	}
	else
	{
		while (just_smaller_operator_position > 0)
		{
			rotate_a_or_b(stack_b, 'b');
			just_smaller_operator_position--;
		}
	}
	if (operator_position > ft_lstsize(*stack_a)/2)
	{
		while (operator_position < ft_lstsize(*stack_a))
		{
			revrotate_a_or_b(stack_a, 'a');
			operator_position++;
		}
	}
	else
	{
		while (operator_position > 0)
		{
			rotate_a_or_b(stack_a, 'a');
			operator_position--;
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
	int     max_operator_position;
	int     node_number;

	t_list *aux = *stack;
	
	max_number = *(int *)(*stack)->content;
	max_operator_position = 0;
	node_number = 0;
	while (*stack)
	{
		if (*(int *)(*stack)->content > max_number)
		{
			max_number = *(int *)(*stack)->content;
			max_operator_position = node_number;
		}
		*stack = (*stack)->next;
		node_number++;
	}
	*stack = aux;
	if (max_operator_position > size/2)
	{
		while (max_operator_position < size)
		{
			revrotate_a_or_b(stack, 'b');
			max_operator_position++;
		}
	}
	else
	{
		while (max_operator_position > 0)
		{
			rotate_a_or_b(stack, 'b');
			max_operator_position--;
		}
	}
}

void	order_stack(t_list **stack_a, int operator_position)
{
	/* printf("Number position: %d\n", operator_position);
	printf("Stack size: %d\n", ft_lstsize(*stack_a)); */
	/* if (operator_position == -1)
	{
		//move_max_num_on_top(stack_a, ft_lstsize(*stack_a));
		rotate_a_or_b(stack_a, 'a');
	} */
	if (operator_position == -1)
	{
		operator_position = get_smallest_number_position(stack_a);
		//printf ("Number position: %d\nList size: %d\n", operator_position, ft_lstsize(*stack_a));
		order_stack(stack_a, operator_position);
		return ;
	}
	if (operator_position == ft_lstsize(*stack_a) - 1)
	{
		//printf("Debería entrar aquí\n");
		revrotate_a_or_b(stack_a, 'a');
	}
	else if (operator_position > ft_lstsize(*stack_a)/2)
	{
		//while(operator_position < ft_lstsize(*stack_a) - 1)
		while(operator_position < ft_lstsize(*stack_a))
		{
			revrotate_a_or_b(stack_a, 'a');
			operator_position++;
		}
	}
	else
	{
		while (operator_position > 0)
		{
			rotate_a_or_b(stack_a, 'a');
			operator_position--;
		}
	}
}
