/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:23:45 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/27 00:56:08 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    rotate_a(t_list **lst)
{
    t_list  *aux;

    if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
        return ;
    aux = ((*lst)->next);
    ft_lstadd_back(lst, (*lst));
    (*lst) = aux;
    if (rotate_a != rotate)
        write(1,"ra\n", 3);
}

void    rotate_b(t_list **lst)
{
    t_list  *aux;

    if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
        return ;
    aux = ((*lst)->next);
    ft_lstadd_back(lst, (*lst));
    (*lst) = aux;
    if (rotate_b != rotate)
        write(1,"rb\n", 3);
}

void    rotate(t_list **lst_a, t_list **lst_b)
{
    if (!lst_a || !(*lst_a) || !(*lst_a)->next || !(*lst_a)->next->next ||
        !lst_b || !(*lst_b) || !(*lst_b)->next || !(*lst_b)->next->next)
        return ;
    rotate_a(lst_a);
    rotate_b(lst_b);
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
    if (revrotate_a != revrotate)
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
    if (revrotate_b != revrotate)
        write(1,"rrb\n", 4);
}

void    revrotate(t_list **lst_a, t_list **lst_b)
{
    if (!lst_a || !(*lst_a) || !(*lst_a)->next || !(*lst_a)->next->next ||
        !lst_b || !(*lst_b) || !(*lst_b)->next || !(*lst_b)->next->next)
        return ;
    revrotate_a(lst_a);
    revrotate_b(lst_b);
    write(1, "rrr\n", 3);
}
