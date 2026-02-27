/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:46:53 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/25 13:46:53 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_data *data, char **nums_split, int status)
{
	if (nums_split)
		free_split(nums_split);
	if (data && data->stack_a)
	{
		free(data->stack_a);
		data->stack_a = NULL;
	}
	if (status == 1)
		write(2, "Error\n", 6);
	exit(status);
}

void	free_split(char **words)
{
	size_t	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	//habria que porteger en caso este vacio el array o el primero nodo?
	
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	//deberiamos apuntarlo a nulo? si **stack fue creado con &stack no necesitamos hacer free pero si dejar *stack a NULL?;
}
