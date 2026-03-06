/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/03/06 17:40:21 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_name(int strategy)
{
	if (strategy == 1)
		return ("Adaptive");
	if (strategy == 2)
		return ("Simple");
	if (strategy == 3)
		return ("Medium");
	return ("Complex");
}

static char	*get_complexity(t_data *data)
{
	if (data->strategy == 1)
	{
		if (data->size <= 5)
			return ("O(n²)");
		if (data->size <= 50)
		{
			if (data->disorder < 0.15)
				return ("O(n²)");
			else
				return ("O(n√n)");
		}
		if (data->size <= 200)
		{
			if (data->disorder < 0.1)
				return ("O(n²)");
			else
				return ("O(n√n)");
		}
		return ("O(n log n)");
	}
	if (data->strategy == 2)
		return ("O(n²)");
	if (data->strategy == 3)
		return ("O(n√n)");
	return ("O(n log n)");
}

static void	print_disorder_fd(double disorder, int fd)
{
	int	int_part;
	int	dec_part;

	disorder = disorder * 100;
	int_part = (int)disorder;
	dec_part = (int)((disorder - int_part) * 100);
	ft_putnbr_fd(int_part, fd);
	write(fd, ".", 1);
	if (dec_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(dec_part, fd);
}

static void	print_ops_breakdown(t_data *data)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(data->stats.sa, 2);
	write(2, "  sb: ", 6);
	ft_putnbr_fd(data->stats.sb, 2);
	write(2, "  ss: ", 6);
	ft_putnbr_fd(data->stats.ss, 2);
	write(2, "  pa: ", 6);
	ft_putnbr_fd(data->stats.pa, 2);
	write(2, "  pb: ", 6);
	ft_putnbr_fd(data->stats.pb, 2);
	write(2, "\n", 1);
	write(2, "[bench] ra: ", 12);
	ft_putnbr_fd(data->stats.ra, 2);
	write(2, "  rb: ", 6);
	ft_putnbr_fd(data->stats.rb, 2);
	write(2, "  rr: ", 6);
	ft_putnbr_fd(data->stats.rr, 2);
	write(2, "  rra: ", 7);
	ft_putnbr_fd(data->stats.rra, 2);
	write(2, "  rrb: ", 7);
	ft_putnbr_fd(data->stats.rrb, 2);
	write(2, "  rrr: ", 7);
	ft_putnbr_fd(data->stats.rrr, 2);
	write(2, "\n", 1);
}

void	print_benchmark(t_data *data)
{
	if (!data->bench_mode)
		return ;
	write(2, "[bench] disorder:  ", 19);
	print_disorder_fd(data->disorder, 2);
	write(2, "%\n", 2);
	write(2, "[bench] strategy:  ", 19);
	write(2, get_strategy_name(data->strategy),
			ft_strlen(get_strategy_name(data->strategy)));
	write(2, " / ", 3);
	write(2, get_complexity(data), ft_strlen(get_complexity(data)));
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(data->stats.total, 2);
	write(2, "\n", 1);
	print_ops_breakdown(data);
}
