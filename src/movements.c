/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:58:47 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/25 15:59:53 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_list **lst)
{
    t_list  *aux;
    
    if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
        return ;
    aux = (*lst)->next;
    (*lst)->next = aux->next;
    aux->next = (*lst);
    (*lst) = aux;
    write(1, "sa\n", 3);
}

void    rotate_a(t_list **lst)
{
    t_list  *aux;

    if (!lst || !(*lst) || !(*lst)->next || !(*lst)->next->next)
        return ;
    aux = ((*lst)->next);
    ft_lstadd_back(lst, (*lst));
    (*lst) = aux;
    write(1,"ra\n", 3);
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
    write(1, "rra\n", 4);
}