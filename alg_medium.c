/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:44 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/04 14:23:11 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack(char *name, t_stack *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("[%d|%d] ", stack->number, stack->index);
		stack = stack->next;
	}
	printf("\n");
}
static void	push_to_stack_b(t_stack **a, t_stack **b, int k, t_data *data)
{
	int	i;

	i = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= k + i)
		{
			pb(a, b, data);
			if ((*b)->index <= i)
				rb(b, data);
			i++;
		}
		else
			ra(a, data);
	}
}

static int	find_max_pos(t_stack *b)
{
	int	tmp;
	int	pos;
	int	i;

	tmp = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (tmp < b->index)
		{
			tmp = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static int	stack_size(t_stack *b)
{
	int	i;

	i = 0;
	while (b)
	{
		b = b->next;
		i++;
	}
	return (i);
}

static void	back_to_stack_a(t_stack **a, t_stack **b, t_data *data)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (*b)
	{
		tmp = *b;
		while (tmp->index != data->size - 1 - i)
			tmp = tmp->next;
		if (find_max_pos(*b) <= (stack_size(*b) / 2))
		{
			while ((*b)->index != tmp->index)
				rb(b, data);
		}
		else
		{
			while ((*b)->index != tmp->index)
				rrb(b, data);
		}
		pa(a, b, data);
		i++;
	}
}

void	medium(t_stack **a, t_stack **b, t_data *data)
{
	int	k;

	/*if (data->size <= 20)
		k = 1;
	else*/
	k = (data->size / 20) + 7;
	printf("ANTES:\n");
	print_stack("A", *a);
	print_stack("B", *b);
	push_to_stack_b(a, b, k, data);
	back_to_stack_a(a, b, data);
	printf("\nDESPUÉS:\n");
	print_stack("A", *a);
	print_stack("B", *b);
}

#include <stdlib.h>
#include <stdio.h>

/*
void free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int main(void)
{
	t_data  data;
	t_stack *a;
	t_stack *b;

	// ====== INPUT DE PRUEBA ====== 
	data.size = 5;
	data.stack_a = malloc(sizeof(int) * data.size);

	data.stack_a[0] = 55;
	data.stack_a[1] = 15;
	data.stack_a[2] = 14;
	data.stack_a[3] = 23;
	data.stack_a[4] = 13;

	// ====== CREAR LISTAS ====== 
	a = get_stack_a(&data);
	b = NULL;

	printf("ANTES:\n");
	print_stack("A", a);
	print_stack("B", b);

	// ====== EJECUTAR K-SORT ====== 
	medium(&a, &b, &data);

	printf("\nDESPUÉS:\n");
	print_stack("A", a);
	print_stack("B", b);

	// ====== FREE ====== 
	free_stack(&a);
	free_stack(&b);
	free(data.stack_a);

	return (0);
}
*/