/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:32:04 by drestrep          #+#    #+#             */
/*   Updated: 2022/09/13 18:23:55 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	if (lst)
	{
		if (*lst != NULL)
		{
			aux = *lst;
			while (aux->next)
				aux = aux->next;
			aux->next = new;
			return ;
		}
		*lst = new;
		return ;
	}
}
