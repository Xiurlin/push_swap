/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:48 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/27 04:10:13 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define REPEATED_NUMBERS () write(1, "Error: números repetidos\n", 25) 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void    two_or_three_numbers(t_list **stack_a);
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