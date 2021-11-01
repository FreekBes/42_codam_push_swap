/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 10:55:00 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 16:26:03 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *s)
{
	if (s->size != 2)
		return ;
	if (s->top->num > s->top->next->num)
		rf(s);
}

static void	sort_three(t_stack *s)
{
	int		n1;
	int		n2;
	int		n3;

	while (!is_sorted(s, 1))
	{
		n1 = s->top->num;
		n2 = s->top->next->num;
		n3 = s->top->next->next->num;
		if (n1 > n2 && n2 < n3 && n3 > n1)
			sf(s);
		else if (n1 > n2 && n2 > n3 && n3 < n1)
			sf(s);
		else if (n1 > n2 && n2 < n3 && n3 < n1)
			ra(s);
		else if (n1 < n2 && n2 > n3 && n3 > n1)
			sf(s);
		else if (n1 < n2 && n2 > n3 && n3 < n1)
			rrf(s);
	}
}

static void	sort_five(t_stack *a, t_stack *b)
{
	if (is_sorted(a, 1))
		return ;
	while (a->size > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int		size;
	int		i;
	int		j;

	index_stack(a);
	size = a->size;
	i = 0;
	while (!is_sorted(a, 1))
	{
		j = 0;
		while (j < size)
		{
			if ((a->top->id >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

int	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
	return (1);
}
