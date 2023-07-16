/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/16 22:07:49 by drestrep         ###   ########.fr       */
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
    {
        //max_number_position++;
        max_number_position = size - max_number_position;
    }
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
    printf("El número del stack_a es: %d\n", number);
    while (*stack)
    {
        printf("La lista en la iteración nº%d es: ", node_number);
        printLinkedList(*stack);
        printf("Número justo más pequeño: %d, posición en el stack: %d\n",just_smaller_number, just_smaller_number);
        if (just_smaller_number == 0 && *(int *)(*stack)->content < number)
        {
            printf("Entra?\n");
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
    printf("El número justo más pequeño que %d, es %d, y está en la posición nº%d.\n", number, just_smaller_number, just_smaller_number_position);
    *stack = aux;
    if (just_smaller_number_position > size/2)
    {
        printf("KELOKE VIEJO\n");
        just_smaller_number_position = size - just_smaller_number_position;
    }
    printf("Operaciones necesarias: %d\n", just_smaller_number_position);
    return (just_smaller_number);
}

void    sort_big(t_list **stack_a, t_list **stack_b, int argc)
{
    int position;
    int min_or_max;
    int total_operations = 0;
    int minimum_operations;
    t_list  *aux;

    aux = *stack_a;
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    position = 1;
    minimum_operations = max_num_on_top(stack_b, argc) + 1;
    while (*stack_a)
    {
        min_or_max = check_if_min_or_max(*(int *)(*stack_a)->content, stack_b);
        if (min_or_max == 0)
        {
            /* printf("Stack_a: \n");
            printLinkedList(*stack_a);
            printf("Stack_b: \n");
            printLinkedList(*stack_b);
            printf("El mínimo de operaciones son: %d\n", minimum_operations); */
            total_operations = max_num_on_top(stack_b, argc) + max_or_min_number(position, argc);
            //printf("Total de operaciones: %d\n", total_operations);
            if (total_operations < minimum_operations)
                minimum_operations = total_operations;
        }
        else
        {
            total_operations = middle_number(stack_b, *(int *)(*stack_a)->content, argc);
            if (total_operations < minimum_operations)
                minimum_operations = total_operations;
        }
        *stack_a = (*stack_a)->next;
    }
    *stack_a = aux;
    printf("Stack_a: \n");
            printLinkedList(*stack_a);
            printf("Stack_b: \n");
            printLinkedList(*stack_b);
    printf("El mínimo de operaciones posibles son:  %d\n", minimum_operations);
    exit(0);
}
