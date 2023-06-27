/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:26:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/27 05:51:14 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    equal_number(t_list **parameters)
{
    t_list  *current;
    
    current = (*parameters);
    while (current != NULL) {
        t_list* runner = current->next;
        while (runner != NULL)
        {
            if (current->content == runner->content)
                exit(1);
            runner = runner->next;
        }
        current = current->next;
    }
    return ;
}

void    error_checker(char **argv)
{
    size_t  i;

    i = 1;
    if (!argv)
        return(0);
    argv_compare(argv);
}