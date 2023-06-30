/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:48 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/30 04:24:50 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# define REPEATED_NUMBERS () write(1, "Error: números repetidos\n", 25) 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void printLinkedList(t_list* head);

void    initialize(t_list **stack_a, int argc, char *argv[]);
void    check_duplicate(t_list **parameters);
void    error_checker(char **argv);
void    sort_small_number(t_list **stack_a, int argc);
void    two_numbers(t_list **stack);
void    three_numbers(t_list **stack_a);
void    swap_a(t_list **lst);
void    swap_b(t_list **lst);
void    swap(t_list **lst_a, t_list **lst_b);
void    push_a(t_list **lst_a, t_list **lst_b);
void    push_b(t_list **lst_a, t_list **lst_b);
void    rotate_a(t_list **lst);
void    rotate_b(t_list **lst);
void    rotate(t_list **lst_a, t_list **lst_b);
void    revrotate_a(t_list **lst);
void    revrotate_b(t_list **lst);
void    revrotate(t_list **lst_a, t_list **lst_b);


#endif