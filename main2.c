/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/26 23:35:07 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->size = 0;
	data->strategy = 0;
	data->bench_mode = 0;
	data->disorder = 0.933334;
	data->stats.sa = 0;
	data->stats.sb = 0;
	data->stats.ss = 0;
	data->stats.pa = 0;
	data->stats.pb = 0;
	data->stats.ra = 0;
	data->stats.rb = 0;
	data->stats.rr = 0;
	data->stats.rra = 0;
	data->stats.rrb = 0;
	data->stats.rrr = 0;
	data->stats.total = 0;
}
/* COMO PODRIAMOS AGREGAR EL CONTEO AL BENCHMARK
void	pb(t_data *data)
{
	t_data	data;
	char	**nums_split;
	int		i;
	int		j;

    // ... lógica
    if (data->bench_mode)
    {
        data->stats.pb++;
        data->stats.total++;
    }
    write(1, "pb\n", 3);
}*/
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	init_data(&data);
	i = 1;
	/* Mientras que comiencen con -- se va actualizando tanto el algoritmo y el bench ya que si hay varios algoritmos se va a coger el ultimo siempre */
	/*
    while(av[i] && is_flag(av[i]))
    {
        update_flag(&data, av[i]);
        i++;
    }
    //Si solo hay flags termina sin devolver nadita
    if(!av[i])
        return (0);
    while (av[i])
    {
        nums_split = ft_split(av[i], ' ');
        if (!nums_split)
        free_and_exit(&data, NULL, 1);
    if (!process_num(nums_split, &data))
    free_and_exit(&data, nums_split, 1);
    free_split(nums_split);
    i++;
    }
    */
	while (av[i])
	{
		if (is_flag(av[i]))
		{
			update_flag(&data, av[i]);
		}
		else
		{
			nums_split = ft_split(av[i], ' ');
			if (!nums_split)
				free_and_exit(&data, NULL, 1);
			if (!process_num(nums_split, &data))
				free_and_exit(&data, nums_split, 1);
			free_split(nums_split);
		}
		i++;
	}
	if (data.size == 0)
		free_and_exit(&data, NULL, 1);
	if (check_duplicates(data.stack_a, data.size))
		free_and_exit(&data, NULL, 1);
	/*Aqui envio la data a tu funcion ALBITA*/
	data->disorder = get_disorder(data.stack_a, data.size);
	choose_algorithm(&data);
	// --- BLOQUE DE PRUEBA: BORRAR ANTES DE ENTREGAR ---
	if (data.stack_a)
	{
		j = 0;
		printf("\n--- DEBUG DATA ---\n");
		printf("Strategy:   %d\n", data.strategy);
		printf("Bench Mode: %d\n", data.bench_mode);
		printf("Stack Size: %d\n", data.size);
		printf("Stack A:    ");
		while (j < data.size)
		{
			printf("[%d] ", data.stack_a[j]);
			j++;
		}
		printf("\n------------------\n\n");
	}
	// ------------------------------------------------
	if (data.bench_mode)
		print_benchmark(&data);
	free_and_exit(&data, NULL, 0);
	return (0);
}
