/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:30:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/24 11:53:47 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_small(t_list **stack_a, t_list **stack_b, int argc)
{
    if (argc == 2)
    {
        two_numbers(stack_a);
        return ;
    }
    if (argc == 3)
    {
        three_numbers(stack_a);
        return ;
    }
    if (argc == 4 || argc == 5)
    {
        four_or_five_numbers(stack_a, stack_b, argc);
        return ;
    }
}

/* void    sort_big(t_list **stack_a, t_list **stack_b, int argc)
{
    while ((*stack_a))
    {
        stack_a = find_smallest_number(stack_a, argc);
        push_b(stack_a, stack_b);
    }
    while ((*stack_b))
        push_a(stack_a, stack_b);
} */

void printLinkedList(t_list* head)
{
    t_list* current;
    current = head;

    while (current != NULL) {
        printf("%d ", *(int*)current->content);
        current = current->next;
    }
    printf("\n");
}

void    two_numbers(t_list **stack)
{
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
        swap_a(stack);
}

void    three_numbers(t_list **stack)
{
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content < *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content < *(int *)(*stack)->next->next->content)
        swap_a(stack);
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
    {
        swap_a(stack);
        revrotate_a_or_b(stack, 'a');
    }
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content < *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
        rotate_a_or_b(stack, 'a');
    if (*(int *)(*stack)->content < *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content < *(int *)(*stack)->next->next->content)
    {
        swap_a(stack);
        rotate_a_or_b(stack, 'a');
    }
    if (*(int *)(*stack)->content < *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
        revrotate_a_or_b(stack, 'a');
    //printLinkedList(*stack);
}

void    four_or_five_numbers(t_list **stack_a, t_list **stack_b, int size)
{
    if (size == 4)
    {
        stack_a = find_smallest_number(stack_a, size);
        push_b(stack_a, stack_b);
        three_numbers(stack_a);
        push_a(stack_a, stack_b);
        //printLinkedList(*stack_a);
    }
    if (size == 5)
    {
        stack_a = find_smallest_number(stack_a, size);
        push_b(stack_a, stack_b);
        stack_a = find_smallest_number(stack_a, size);
        push_b(stack_a, stack_b);
        three_numbers(stack_a);
        push_a(stack_a, stack_b);
        push_a(stack_a, stack_b);
        //printLinkedList(*stack_a);
    }
}