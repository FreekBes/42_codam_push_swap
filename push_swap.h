/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:40:10 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/29 20:11:03 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_link
{
	int				num;
	int				id;
	struct s_link	*prev;
	struct s_link	*next;
}				t_link;

typedef struct s_stack
{
	char		id;
	int			size;
	t_link		*top;
}				t_stack;

t_stack			*new_stack(char id);
void			free_stack(t_stack *s);
void			print_stack(t_stack *s);
void			debug_stack(t_stack *s);
void			index_stack(t_stack *s);
t_link			*get_stack_link(t_stack *s, int index);
t_link			*get_stack_bottom(t_stack *s);
t_link			*get_stack_biggest(t_stack *s);
t_link			*get_stack_smallest(t_stack *s);
int				get_min_steps_to_reach(t_stack *s, t_link *f);
int				parse_num(t_stack *a, int *n, char *s);
int				push(t_stack *s, t_link *link, int n);
void			push_smallest_to_b(t_stack *a, t_stack *b);
t_link			*pop(t_stack *s);
void			swap(t_stack *s);
void			rotate(t_stack *s);
void			reverse(t_stack *s);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			pf(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			sf(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rf(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrf(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				sort(t_stack *a, t_stack *b);
int				is_sorted(t_stack *s, int dir);

#endif
