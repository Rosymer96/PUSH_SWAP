/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosvela <rosvela@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:18:01 by rosvela           #+#    #+#             */
/*   Updated: 2026/02/19 15:18:03 by rosvela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stats {
    int sa; int sb; int ss;
    int pa; int pb;
    int ra; int rb; int rr;
    int rra; int rrb; int rrr;
    int total;
} t_stats;

typedef struct s_data {
    int *stack_a;
    int size;
    int strategy;
    t_stats stats;
    int bench_mode;
    double disorder;
} t_data;

// Gestion de memoria y salida en caso de error
void free_and_exit(t_data *data, char **nums_split, int status);
void free_split(char **words);
//Parseo y flags
int is_flag(char *arg);
void update_flag(t_data *data, char *arg);
int process_num(char **nums_split, t_data *data);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
//Validacion y conversion de numeros
int is_numeric(char *str);
long long ft_atoll(char *str);
int check_duplicates(int *stack, int size);
int add_to_stack(t_data *data, int val);

//Funciones de algoritmos ALBA


//Funciones de impresion en terminal
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
void print_benchmark(t_data *data);









#endif