/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:48 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/16 21:26:41 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# define REPEATED_NUMBERS () write(1, "Error: números repetidos\n", 25) 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void    printLinkedList(t_list* head);
int     push_swap_atoi(const char *str);
void    check_spaces(char *str);
void    check_one_argument(t_list **str);
void    sort_big(t_list **stack_a, t_list **stack_b, int argc);
int     max_num_on_top(t_list **stack, int size);
int     max_or_min_number(int position, int size);
int     middle_number(t_list **stack, int number, int size);
int     check_if_min_or_max(int stack_a_number, t_list **stack);

// INITIALIZER
void    initialize(t_list **stack_a, int argc, char *argv[]);
char    **new_stack(char **stack);

// ERROR CHECKER
void    error_checker(t_list ** stack);
void    check_is_number(char **argv);
void    check_if_ordered(t_list **stack, int caller);
void    check_duplicate(t_list **parameters);

// ALGORITHMS
void    sort_small(t_list **stack_a, t_list **stack_b, int argc);
void    sort_big(t_list **stack_a, t_list **stack_b, int argc);
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