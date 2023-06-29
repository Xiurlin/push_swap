/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:26:13 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/27 23:30:31 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    check_duplicate(t_list **parameters)
{
    t_list  *current;
    t_list  *runner;
    current = (*parameters);
    while (current != NULL) {
        runner = current->next;
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
    check_duplicate(argv);
}