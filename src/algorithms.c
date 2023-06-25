/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:30:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/25 17:09:13 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    two_or_three_numbers(t_list **stack_a)
{
    t_list  *aux;

    if (!stack_a)
        return(0);
    aux = *stack_a;
    
    if (aux->content > aux->next->content &&
        aux->next->content < aux->next->next->content &&
        aux->content < aux->next->next->content)
        swap_a(aux);

    if (aux->content > aux->next->content &&
        aux->next->content > aux->next->next->content &&
        aux->content > aux->next->next->content)
    {
        swap_a(aux);
        revrotate_a(aux);
    }
    if (aux->content > aux->next->content &&
        aux->next->next < aux->next->next->next &&
        aux->content > aux->next->next->next)
        rotate_a(aux);
    if (aux->content < aux->next->content &&
        aux->next->next > aux->next->next->next &&
        aux->content < aux->next->next->next)
    {
        swap_a(aux);
        rotate_a(aux);
    }
    if (aux->content < aux->next->content &&
        aux->next->next > aux->next->next->next &&
        aux->content > aux->next->next->next)
        revrotate_a(aux);
}
