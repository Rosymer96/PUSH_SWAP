/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:02 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/24 09:40:11 by albben-a         ###   ########.fr       */
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

typedef struct s_data {
    int *stack_a;
    int size;
    int strategy;
    int bench_mode;
    double disorder;
} t_data;

//escoge el algoritmo en función de la flag
void	choose_algorithm(t_data *data);
//generan la estructura con la que trabajamos luego
t_stack	**get_stack_a(t_data *data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content, int index);
//función algoritmo adaptativo
void	adaptive(t_data *data);

#endif