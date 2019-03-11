#include <fcntl.h>
#include "lem_in.h"

static void	init_lem(int fd, t_lemin *lem)
{
	ft_bzero(lem, sizeof(t_lemin));
	parsing(fd, lem);
//	system("leaks Lem_in -q > leaks");
	lem->amount = count_amount_rooms(lem);
	lem->list_v = get_list_v(lem, lem->vert);
	lem->mas_res = NULL;
}

t_ways	*get_min_ways(t_mas_ways *mas_ways)
{
	t_mas_ways	*min;

	min = mas_ways;
	while (mas_ways)
	{
		if (mas_ways->iter < min->iter)
			min = mas_ways;
		mas_ways = mas_ways->next;
	}
	return (min->ways);
}

void	go_ants_in_way(t_way *way, t_lemin *lem, int *steps, int *ant)
{
	t_way	*end;

	end = way->prev;
	while (end->prev != way)
	{
		if (end->prev->ant)
		{
			ft_printf("L%d-%s ", end->prev->ant, end->vert->name);
			end->ant = end->prev->ant;
			end->prev->ant = 0;
			(*steps)++;
		}
		end = end->prev;
	}
	if (lem->ants)
	{
		ft_printf("L%d-%s ", ++(*ant), end->vert->name);
		end->ant = *ant;
		lem->ants--;
		(*steps)++;
	}
}

void	ants_go(t_ways *ways, t_lemin *lem)
{
	t_ways	*begin;
	int 	steps;
	int 	i;
	int 	tmp;
	int 	ant;

	ant = 0;
	i = 0;
	steps = 1;
	begin = ways;
	while (steps)
	{
		steps = 0;
		ways = begin;
		while (ways)
		{
			tmp = number_can_way(ways, begin);
			if (lem->ants >= tmp)
				go_ants_in_way(ways->way, lem, &steps, &ant);
			else
				break ;
			ways = ways->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("{RED}%i iters\n{EOC}", i - 1);
}


//void	sort_mas_ways(t_mas_ways *mas_ways)
//{
//	while (mas_ways)
//	{
//		bubble_sort_list(&mas_ways->ways);
//		mas_ways = mas_ways->next;
//	}
//}


int main()
//int main(int ac, char **av)
{
	t_lemin 	*lem;
	int 		fd;
	int 		i;
	t_mas_ways	*result;


//	if (ac)
//		;
//	fd = open(av[1], O_TRUNC | O_RDONLY);
	fd = open("superpos", O_RDONLY);
	lem = (t_lemin*)malloc(sizeof(t_lemin));
	init_lem(fd, lem);

	i = 1;
//	write_result(lem, i);



	write_result(lem, 5);
//	while (i <= 4)
//	{
//		write_result(lem, i);
//		i++;
//	}
//	get_iters(lem->big_mas_ways, lem);
	result = get_result(lem->mas_res);
//	result = get_min_mas_ways(lem->big_mas_ways);
	print_result(result, lem->target);

//	print_mas_ways(lem->big_mas_ways);

//	get_mas_ways(lem);
////	sort_mas_ways(lem->mas_ways);
//	print_min_mas_ways(lem->big_mas_ways);
	ants_go(result->ways, lem);
	ft_printf("{YELLOW}iters - %d{EOC}   {RED}target - %d{EOC}\n", result->iter, lem->target);

	return 0;
}