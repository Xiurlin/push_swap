/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:56 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/14 03:37:52 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return(1);
	
	stack_a	= NULL;
	stack_b = NULL;
	initialize(&stack_a, argc, argv);
	argc = ft_lstsize(stack_a);
	//printf("El tamaño de la lista es de %d\n", argc);
	error_checker(&stack_a);
	if (argc <= 5)
		sort_small(&stack_a, &stack_b, argc);
	else
		sort_big(&stack_a, &stack_b, argc);
	return (0);
}