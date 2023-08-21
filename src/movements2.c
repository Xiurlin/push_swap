/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:23:45 by drestrep          #+#    #+#             */
/*   Updated: 2023/08/21 06:49:37 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    rotate_a_or_b(t_list **lst, char c)
{
    t_list  *aux;
    t_list  *last;

    aux = ((*lst)->next);
    last = ft_lstlast(*lst);
    last->next = (*lst);
    (*lst)->next = NULL;
    (*lst) = aux;
	if (c == 'a')
    	write(1,"ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void    rotate(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next ||
        !stack_b || !(*stack_b) || !(*stack_b)->next || !(*stack_b)->next->next)
        return ;
	/* printf("El stack_a antes del rotate es: ");
	printLinkedList(*stack_a);
	printf("El stack_b es: ");
	printLinkedList(*stack_b); */
    rotate_a_or_b(stack_a, 'c');
    rotate_a_or_b(stack_b, 'c');
	/* printf("El stack_a antes del rotate es: ");
	printLinkedList(*stack_a);
	printf("El stack_b es: ");
	printLinkedList(*stack_b); */
    write(1, "rr\n", 3);
}

void    revrotate_a(t_list **lst)
{
    t_list  *second2last;
    t_list  *last;

    if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
        return ;
    second2last = NULL;
    last = (*lst);
    while (last->next)
    {
        second2last = last;
        last = last->next;
    }
    second2last->next = NULL;
    last->next = (*lst);
    (*lst) = last;
    write(1,"rra\n", 4);
}

void    revrotate_b(t_list **lst)
{
    t_list  *second2last;
    t_list  *last;

    if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
        return ;
    second2last = NULL;
    last = (*lst);
    while (last->next)
    {
        second2last = last;
        last = last->next;
    }
    second2last->next = NULL;
    last->next = (*lst);
    (*lst) = last;
    write(1,"rrb\n", 4);
}

void    revrotate(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next ||
        !stack_b || !(*stack_b) || !(*stack_b)->next || !(*stack_b)->next->next)
        return ;
    revrotate_a(stack_a);
    revrotate_b(stack_b);
    write(1, "rrr\n", 3);
}

