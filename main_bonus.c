/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:03:44 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:36:42 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->size = 0;
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

static void	parse_and_process(t_data *data, char **av)
{
	char	**nbr;
	int		i;

	i = 1;
	while (av[i])
	{
		nbr = ft_split(av[i], ' ');
		if (!nbr)
			free_and_exit(data, NULL, 1);
		if (!process_num(nbr, data))
			free_and_exit(data, nbr, 1);
		free_split(nbr);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	init_data(&data);
	parse_and_process(&data, av);
	if (data.size == 0)
		free_and_exit(&data, NULL, 1);
	if (check_duplicates(data.stack_a, data.size))
		free_and_exit(&data, NULL, 1);
	check_mov(&data);
	free_and_exit(&data, NULL, 0);
	return (0);
}
