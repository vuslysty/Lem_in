//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

t_lema		*create_lema(t_node *node)
{
	t_lema		*lema;

	lema = (t_lema*)ft_memalloc(sizeof(t_lema));
	lema->node = node;
	return (lema);
}

void		add_lema(t_lema **lema, t_lema *new_lema)
{
	if (*lema != NULL)
		new_lema->next = *lema;
	*lema = new_lema;
}

int 		is_in_lema(t_lema *lema, t_node *node)
{
	while (lema)
	{
		if (lema->node == node)
			return (1);
		lema = lema->next;
	}
	return (0);
}

t_lema		*create_lema_list(t_top_nodes *top, )
{
	t_lema		*lema;
	t_pretend	*pret;

	lema = NULL;
	while (top)
	{
		pret = top->pretend;
		while (pret)
		{
			if (pret->node->v->color != FOUND && !is_in_lema(lema, pret->node))
				add_lema(&lema, create_lema(pret->node));
			pret = pret->next;
		}
		top = top->next;
	}
	return (lema);
}