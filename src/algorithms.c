/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:30:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/30 04:28:00 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_small_number(t_list **stack_a, int argc)
{
    argc--;
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
    /*
    if (argc == 4)
    {
        four_numbers(stack_a, stack_b);
        return ;
    }
    
    if (argc == 5)
    {
        five_numbers(stack_a, stack_b);
        return ;
    }
    */
}

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
    if (*(int *)(*stack)->content < *(int *)(*stack)->next->content)
        swap_a(stack);
}

void    three_numbers(t_list **stack)
{
    //printf("Hola\n");
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content < *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content < *(int *)(*stack)->next->next->content)
    {
        printf("Hola\n");
        swap_a((stack));
    }
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
    {
        printf("Hola\n");
        swap_a((stack));
        revrotate_a((stack));
    }
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content < *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
    {
        printf("Hola\n");
        rotate_a((stack));
    }
    if (*(int *)(*stack)->content < *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content < *(int *)(*stack)->next->next->content)
    {
        printf("Hola\n");
        swap_a((stack));
        rotate_a((stack));
    }
    if (*(int *)(*stack)->content < *(int *)(*stack)->next->content &&
        *(int *)(*stack)->next->content > *(int *)(*stack)->next->next->content &&
        *(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
    {
        printf("Hola\n");
        revrotate_a((stack));
    }
}
/*
void    four_numbers(stack_a, stack_b)
{
    
}
*/