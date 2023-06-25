/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:33:56 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/25 17:11:22 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;

	if (argc <= 1)
		exit(1);
	if (1 < argc <= 3)
		two_or_three_numbers(&stack_a);
	
	return (0);
}

/*
int main()
{
	printf("Hello World\n");
	return (0);
}
*/