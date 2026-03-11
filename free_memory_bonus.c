/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:46:53 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/09 21:01:16 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_and_exit(t_data *data, char **nums_split, int status)
{
	if (nums_split)
		free_split(nums_split);
	if (data)
	{
		if (data->stack_a)
		{
			free(data->stack_a);
			data->stack_a = NULL;
		}
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

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
