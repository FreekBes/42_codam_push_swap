/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:40:10 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/24 16:43:30 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_frame
{
	int				num;
	struct s_frame	*next;
}				t_frame;

typedef struct s_stack
{
	char		id;
	int			size;
	t_frame		*top;
}				t_stack;

t_stack			*new_stack(char id);
void			free_stack(t_stack *s);
void			print_stack(t_stack *s);
void			debug_stack(t_stack *s);
t_frame			*get_stack_frame(t_stack *s, int index);
t_frame			*get_stack_bottom(t_stack *s);
int				ps_atoi(char *s, int *n);
int				is_dup(t_stack *s, int n);
int				push(t_stack *s, int n);
t_frame			*pop(t_stack *s);
void			swap(t_stack *s);
void			rotate(t_stack *s);
void			reverse(t_stack *s);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			sf(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			pf(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rf(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrf(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				operate(t_stack *a, t_stack *b);
int				is_sorted(t_stack *s, int dir);
void			sort_three(t_stack *s);
void			sort_five(t_stack *a, t_stack *b);

#endif
