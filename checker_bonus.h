/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:05:16 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:42:46 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}		t_stats;

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;

}					t_stack;

typedef struct s_data
{
	int				*stack_a;
	int				size;
	t_stats			stats;

}					t_data;

char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);

void				free_and_exit(t_data *data, char **nums_split, int status);
void				free_split(char **words);
void				free_stack(t_stack **stack);

int					process_num(char **nums_split, t_data *data);
int					check_duplicates(int *stack, int size);
char				**ft_split(char const *s, char c);

t_stack				*get_stack_a(t_data *data);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);

void				check_mov(t_data *data);

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

#endif