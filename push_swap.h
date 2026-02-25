/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:02 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/25 11:43:33 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stats
{
	int sa; int sb; int ss;
	int pa; int pb;
	int ra; int rb; int rr;
	int rra; int rrb; int rrr;
	int total;
}	t_stats;

typedef struct s_data
{
	int		*stack_a;
	int		size;
	int		strategy;
	t_stats	stats;
	int		bench_mode;
	double	disorder;
}	t_data;

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;

}	t_stack;

//escoge el algoritmo en función de la flag
void	choose_algorithm(t_data *data);
//saca el indice de desorden
double	get_disorder(int *a, int size);
//generan la estructura con la que trabajamos luego
t_stack	**get_stack_a(t_data *data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content, int index);
t_stack	*ft_lstlast(t_stack *lst);
//función algoritmo adaptativo
void	adaptive(t_data *data, double disorder);
//swap functions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
//push functions
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//rotate functions
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//reverse rotate funtions
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif