/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:30:35 by drestrep          #+#    #+#             */
/*   Updated: 2023/07/30 04:24:33 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list  **find_smallest_number(t_list **stack, int size)
{
    int     i;
    int     min_nb;
    t_list  *aux;
    
    i = 0;
    min_nb = *(int *)(*stack)->content;
    aux = (*stack);
    while ((*stack))
    {
        if (*(int *)(*stack)->content < min_nb)
            min_nb = *(int *)(*stack)->content;
        (*stack) = (*stack)->next;
    }
    (*stack) = aux;
    while (*(int *)(*stack)->content != min_nb)
    {
        (*stack) = (*stack)->next;
        i++;
    }
    (*stack) = aux;
    if (i < size/2)
    {
        while (i > 0)
        {
            rotate_a(stack);
            i--;
        }
    }
    else
    {
        while (*(int *)(*stack)->content != min_nb)
            revrotate_a(stack);
    }
    return(stack);
}


int	push_swap_atoi(const char *str)
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

int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
	{
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}
