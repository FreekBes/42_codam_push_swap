/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 10:55:00 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 17:44:48 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack of only two numbers
 * @param t_stack *s:	The stack to sort
 */
static void	sort_two(t_stack *s)
{
	if (s->size != 2)
		return ;
	if (s->top->num > s->top->next->num)
		rf(s);
}

/**
 * Sorts a stack of only three numbers
 * @param t_stack *s:	The stack to sort
 */
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

/**
 * Sorts a stack of up four or five numbers using two stacks
 * @param t_stack *a:	The stack to sort
 * @param t_stack *b:	The stack to temporarily use for sorting
 */
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

/**
 * Sorts a stack using radix sort using two stacks, supports any stack size
 * @param t_stack *a:	The stack to sort
 * @param t_stack *b:	The stack to temporarily use for sorting
 */
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

/**
 * Initial sorting function that chooses the right algorithm to use based on
 * the size of the stack to sort
 * @param t_stack *a:	The stack to sort
 * @param t_stack *b:	A stack to use temporarily for sorting
 */
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
