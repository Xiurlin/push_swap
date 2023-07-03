/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:48 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/03 04:09:37 by drestrep         ###   ########.fr       */
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

// INITIALIZER
void    initialize(t_list **stack_a, int argc, char *argv[]);

// ERROR CHECKER
void    check_duplicate(t_list **parameters);
void    error_checker(char **argv);

// ALGORITHMS
void    sort_small_number(t_list **stack_a, t_list **stack_b, int argc);
void    two_numbers(t_list **stack);
void    three_numbers(t_list **stack_a);
void    four_or_five_numbers(t_list **stack_a, t_list **stack_b, int size);

// OPERATIONS
t_list  **find_smallest_number(t_list **stack_a, int size);

void    swap_a(t_list **lst);
void    swap_b(t_list **lst);
void    swap(t_list **lst_a, t_list **lst_b);
void    push_a(t_list **lst_a, t_list **lst_b);
void    push_b(t_list **lst_a, t_list **lst_b);
//void    rotate_a(t_list **lst);
void    rotate_b(t_list **lst);
void    rotate(t_list **lst_a, t_list **lst_b);
void	rotate_a(t_list **lst);
void    revrotate_a(t_list **lst);
void    revrotate_b(t_list **lst);
void    revrotate(t_list **lst_a, t_list **lst_b);


#endif