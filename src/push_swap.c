/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:56 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/29 02:06:17 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	//size_t	i;

	//i = 1;
	if (argc <= 1)
		return(1);
	error_checker(argv);
	stack_b = NULL;
	initialize(stack_a, argc, argv);
	if (argc <= 5)
		sort_small_number(&stack_a);
	
	return (0);
}

/*
int main()
{
	printf("Hello World\n");
	return (0);
}
*/