#include "list.h"

void	ft_swap(t_list *a, t_list *b)
{
	int		tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*lst2 = lst;
	int		p = 1;
	int		tmp;

	while (p == 1)
	{
		p = 0;
		while (lst2 != 0 && lst2->next != 0)
		{
			p = 0;
			if (cmp(lst2->data, lst2->next->data) == 0)
			{
				ft_swap(lst2, lst2->next);
				p = 1;
			}
			lst2 = lst2->next;
		}
		lst2 = lst;
	}
	return (lst);
}