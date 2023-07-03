/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:30:35 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/03 04:25:01 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list  **find_smallest_number(t_list **stack, int size)
{
    int     i;
    int     min_nb;
    t_list  *aux;
    
    i = 0;
    min_nb = *(int *)(*stack)->content;
    aux = (*stack);
    while ((*stack))
    {
        if (*(int *)(*stack)->content < min_nb)
            min_nb = *(int *)(*stack)->content;
        (*stack) = (*stack)->next;
    }
    (*stack) = aux;
    while (*(int *)(*stack)->content != min_nb)
    {
        (*stack) = (*stack)->next;
        i++;
    }
    (*stack) = aux;
    if (i < size/2)
    {
        while (i > 0)
        {
            rotate_a(stack);
            i--;
        }
    }
    else
    {
        while (*(int *)(*stack)->content != min_nb)
            revrotate_a(stack);
    }
    return(stack);
}