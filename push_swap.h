/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:02 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/25 11:34:50 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;

}	t_stack;

typedef struct s_data
{
	int		*stack_a;
	int		size;
	int		strategy;
	int		bench_mode;
	double	disorder;
}	t_data;

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

#endif