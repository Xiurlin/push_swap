#include "include/push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		if (aux->next == NULL)
			return (aux);
		aux = aux->next;
	}
	return (aux);
}

int main()
{
	t_list	**lst;

	printf("%s", ft_lstlast((*lst)));
	return (0);
}