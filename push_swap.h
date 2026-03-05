/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:02 by albben-a          #+#    #+#             */
/*   Updated: 2026/02/27 11:52:32 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stats
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_stats;

typedef struct s_data
{
	int				*stack_a;
	int				size;
	int				strategy;
	t_stats			stats;
	int				bench_mode;
	double			disorder;
	int				*lis_array;
	int				lis_size;
}					t_data;

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos; 
	int				cost_a; // ra es positivo + y rra es -
	int				cost_b;
	struct s_stack	*next;

}					t_stack;

// Gestion de memoria y salida en caso de error
void				free_and_exit(t_data *data, char **nums_split, int status);
void				free_split(char **words);
void				free_stack(t_stack **stack);
//Parseo y flags
int					is_flag(char *arg);
void				update_flag(t_data *data, char *arg);
int					process_num(char **nums_split, t_data *data);
char				**ft_split(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
//Validacion y conversion de numeros
int					is_numeric(char *str);
long long			ft_atoll(char *str);
int					check_duplicates(int *stack, int size);
int					add_to_stack(t_data *data, int val);
//escoge el algoritmo en función de la flag
void				choose_algorithm(t_data *data);
//saca el indice de desorden
double				get_disorder(int *a, int size);
//generan la estructura con la que trabajamos luego
t_stack				*get_stack_a(t_data *data);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int content, int index, int pos);
t_stack				*ft_lstlast(t_stack *lst);
int get_lst_size(t_stack *stack);
//función algoritmo adaptativo
void				adaptive(t_stack **a, t_stack **b, t_data *data);
//funciones de algoritmo simple

 //funciones de algortimo complex
int *get_lis_ind(t_data *data);
int	is_in_lis(int number, t_data *data);
void find_target(t_stack *a, t_stack *b);
void final_rot(t_stack **a, t_data *data);
int	get_abs(int n);
void	complex(t_stack **a, t_stack **b, t_data *data);

//swap functions
void				sa(t_stack *a, t_data *data);
void				sb(t_stack *b, t_data *data);
void				ss(t_stack *a, t_stack *b, t_data *data);
//push functions
void				pa(t_stack **a, t_stack **b, t_data *data);
void				pb(t_stack **a, t_stack **b, t_data *data);
//rotate functions
void				ra(t_stack **a, t_data *data);
void				rb(t_stack **b, t_data *data);
void				rr(t_stack **a, t_stack **b, t_data *data);
//reverse rotate funtions
void				rra(t_stack **a, t_data *data);
void				rrb(t_stack **b, t_data *data);
void				rrr(t_stack **a, t_stack **b, t_data *data);

void				simple(t_stack **a, t_stack **b, t_data *data);
void				medium(t_stack **a, t_stack **b, t_data *data);
void				complex(t_stack **a, t_stack **b, t_data *data);

//Funciones de impresion en terminal
size_t				ft_strlen(const char *str);
void				ft_putnbr_fd(int n, int fd);
void				print_benchmark(t_data *data);
//funciones para manejar posiciones
int	find_min_pos(t_stack *a);
void set_position(t_stack *stack);
#endif
