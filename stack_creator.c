/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:54 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/04 00:32:08 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static int	get_index(t_data *data, int nbr)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < data->size)
	{
		if (nbr > data->stack_a[i])
			index++;
		i++;
	}
	return (index);
}

t_stack	*get_stack_a(t_data *data)
//genera la lista que enviaremos al algoritmo
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	i = 0;
	a = NULL;
	while (i < data->size)
	{
		node = ft_lstnew(data->stack_a[i], get_index(data, data->stack_a[i]));
		//printf ("index: %i\n", node->index); //comprobación de que funciona
		ft_lstadd_back(&a, node);
		i++;
	}
	return (a);
}
/*
t_stack *get_stack_b(t_data *data) //no hace falta, si se inicia a NULL dentro del algoritmo sirve. Si no estamos creando una llista vacía que luego añade cosas encima
{
	t_stack *b;
	t_stack	*node;
	int	i;

	i = 0;
	b = NULL;
	while (i < data->size)
	{
		node = ft_lstnew(NULL, 0);
		ft_lstadd_back(&b, node);
		i++;
	}
	return (b);
}*/
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

    data.size = 3;
    data.stack_a = malloc(sizeof(int) * data.size);

    data.stack_a[0] = 3;
    data.stack_a[1] = 1;
    data.stack_a[2] = 2;

    printf("Construyendo stack...\n\n");
    a = get_stack_a(&data);

    free_stack(&a);
    free(data.stack_a);

    return (0);
}*/