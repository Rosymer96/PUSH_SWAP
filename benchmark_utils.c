/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/19 15:18:03 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char *get_strategy_name(int strategy)
{
    if (strategy == 0) return ("Adaptive");
    if (strategy == 1) return ("Simple");
    if (strategy == 2) return ("Intermediate");
    return ("Complex");
}

static char *get_complexity(double disorder)
{
	if (disorder < 0.2)
        return ("O(n²)");
	else if (0.2 <= disorder && disorder < 0.5)
        return ("O(n√n)");
    return ("O(n log n)");
}

static void print_disorder_fd(double disorder, int fd)
{
    int int_part;
    int dec_part;

    // sacamos la parte entera casteando
    int_part = (int)disorder; 
    // sacamos los dos decimales restando y multiplicando
    dec_part = (int)((disorder - int_part) * 100);
    // colocamos negativo pero no creo que sea necesario
    if (dec_part < 0) 
        dec_part *= -1;
    // 4. IMPRESIÓN POR PARTES
    ft_putnbr_fd(int_part, fd);    // Imprime "49"
    write(fd, ".", 1);             // Imprime el punto "."
    // imprimos el 0 para que no salga "49.5" en vez de "49.05".
    if (dec_part < 10)
        write(fd, "0", 1);
    ft_putnbr_fd(dec_part, fd);    // escribe el decimal
}

static void print_ops_breakdown(t_data *data)
{
    // Swaps y Pushes
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
    //  Rotates y Reverse Rotates (todo junto)
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

void print_benchmark(t_data *data)
{
    if (!data->bench_mode)
        return ;
    write(2, "[bench] disorder:  ", 19);
    print_disorder_fd(data->disorder, 2);
    write(2, "%\n", 2);
    write(2, "[bench] strategy:  ", 19);
    write(2, get_strategy_name(data->strategy), ft_strlen(get_strategy_name(data->strategy)));
    write(2, " / ", 3);
    write(2, get_complexity(data->disorder), ft_strlen(get_complexity(data->disorder)));
    write(2, "\n", 1);
    write(2, "[bench] total_ops: ", 19);
    ft_putnbr_fd(data->stats.total, 2);
    write(2, "\n", 1);
    print_ops_breakdown(data);
}