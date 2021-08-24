/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:40:10 by fbes          #+#    #+#                 */
/*   Updated: 2021/08/24 18:24:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	char		id;
	int			max;
	int			length;
	int			*stack;
}				t_stack;

t_stack			*new_stack(char id, int maxlen);
void			free_stack(t_stack *s);
void			print_stack(t_stack *s);
int				ps_atoi(char *s, int *n);
int				is_dup(t_stack *s, int n);
void			push(t_stack *s, int n);
void			unshift(t_stack *s, int n);
void			pop(t_stack *s);
void			swap(t_stack *s);
void			rotate(t_stack *s);
void			reverse(t_stack *s);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				operate(t_stack *a, t_stack *b);
int				is_sorted(t_stack *s, int dir);

#endif
