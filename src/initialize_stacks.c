/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:36:27 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/02 21:27:44 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void initialize(t_list **stack_a, int argc, char *argv[])
{
    int i;
	int	*nb;

    i = 1;
    *stack_a = NULL;
    while (i < argc)
    {
        nb = (int *)malloc(sizeof(int));
        *nb = ft_atoi(argv[i]);
        //printf("%d\n", *nb);

        if (i == 1)
            *stack_a = ft_lstnew(nb);
        else
            ft_lstadd_back(stack_a, ft_lstnew(nb));

        i++;
    }
}

/*
long	ft_atol(const char *str)
{
	int	res;
	int	sgn;
	int	i;

	res = 0;
	sgn = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sgn * res);
}
*/