/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:02 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/24 12:20:49 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
    int 			number;
    int 			index;
	struct s_stack	*next;

} t_stack;

//swap functions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
//push functions
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//rotate functions
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
//reverse rotate funtions
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
//list functions needed
t_stack	*ft_lstlast(t_stack *lst); //creo que podemos incluirla en el otro archivo de funciones y ya

#endif