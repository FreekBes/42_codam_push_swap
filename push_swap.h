/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:40:10 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:25:37 by fbes          ########   odam.nl         */
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
void			push(t_stack *s, int n);
void			swap(t_stack *s);
void			rotate(t_stack *s);
void			reverse(t_stack *s);

#endif
