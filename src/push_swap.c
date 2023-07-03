/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:56 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/03 00:55:22 by drestrep         ###   ########.fr       */
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
	
	//error_checker(argv);
	stack_a	= NULL;
	stack_b = NULL;
	initialize(&stack_a, argc, argv);
	//printLinkedList(stack_a);
	if (argc <= 6)
		sort_small_number(&stack_a, &stack_b, argc);
	return (0);
}

/*
int main()
{
	printf("Hello World\n");
	return (0);
}
*/