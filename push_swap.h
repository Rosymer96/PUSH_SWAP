/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:02 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/11 11:56:58 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;

}					t_stack;

void				free_and_exit(t_data *data, char **nums_split, int status);
void				free_split(char **words);
void				free_stack(t_stack **stack);

int					is_flag(char *arg);
void				update_flag(t_data *data, char *arg);
int					process_num(char **nums_split, t_data *data);
char				**ft_split(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					is_numeric(char *str);
long long			ft_atoll(char *str);
int					check_duplicates(int *stack, int size);
int					add_to_stack(t_data *data, int val);

void				choose_algorithm(t_data *data);

double				get_disorder(int *a, int size);

t_stack				*get_stack_a(t_data *data);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int content, int index, int pos);
t_stack				*ft_lstlast(t_stack *lst);
int					get_lst_size(t_stack *stack);

void				simple(t_stack **a, t_stack **b, t_data *data);
void				medium(t_stack **a, t_stack **b, t_data *data);
void				complex(t_stack **a, t_stack **b, t_data *data);
void				adaptive(t_stack **a, t_stack **b, t_data *data);

int					find_min_pos(t_stack *a);
int					find_max_pos(t_stack *b);
int					get_position(t_stack *a, int value);
void				set_position(t_stack *stack);

int					*get_lis_ind(t_data *data);
int					is_in_lis(int number, t_data *data);
void				push_non_lis(t_stack **a, t_stack **b, t_data *data);
void				find_target(t_stack *a, t_stack *b);
void				final_rot(t_stack **a, t_data *data);
int					get_abs(int n);

void				sa(t_stack *a, t_data *data);
void				sb(t_stack *b, t_data *data);
void				ss(t_stack *a, t_stack *b, t_data *data);

void				pa(t_stack **a, t_stack **b, t_data *data);
void				pb(t_stack **a, t_stack **b, t_data *data);

void				ra(t_stack **a, t_data *data);
void				rb(t_stack **b, t_data *data);
void				rr(t_stack **a, t_stack **b, t_data *data);

void				rra(t_stack **a, t_data *data);
void				rrb(t_stack **b, t_data *data);
void				rrr(t_stack **a, t_stack **b, t_data *data);

size_t				ft_strlen(const char *str);
void				ft_putnbr_fd(int n, int fd);
void				print_benchmark(t_data *data);

#endif
