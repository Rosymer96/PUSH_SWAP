/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:27:08 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:02:48 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	continue_find_mov(t_data *data, char *mov, t_stack **a, t_stack **b)
{
	if (ft_strncmp(mov, "ra", 2) == 0)
		ra(a, data);
	else if (ft_strncmp(mov, "rb", 2) == 0)
		rb(b, data);
	else if (ft_strncmp(mov, "rr", 2) == 0)
		rr(a, b, data);
	else if (ft_strncmp(mov, "rra", 3) == 0)
		rra(a, data);
	else if (ft_strncmp(mov, "rrb", 3) == 0)
		rrb(b, data);
	else if (ft_strncmp(mov, "rrr", 3) == 0)
		rrr(a, b, data);
	else
	{
		free_stack(a);
		free_stack(b);
		free(mov);
		free_and_exit(data, NULL, 1);
	}
}

static void	find_mov(t_data *data, char *mov, t_stack **a, t_stack **b)
{
	if (ft_strncmp(mov, "sa", 2) == 0)
		sa(*a, data);
	else if (ft_strncmp(mov, "sb", 2) == 0)
		sb(*b, data);
	else if (ft_strncmp(mov, "ss", 2) == 0)
		ss(*a, *b, data);
	else if (ft_strncmp(mov, "pa", 2) == 0)
		pa(a, b, data);
	else if (ft_strncmp(mov, "pb", 2) == 0)
		pb(a, b, data);
	else
		continue_find_mov(data, mov, a, b);
}

static void	check_order(t_stack *a)
{
	t_stack	*tmp;

	tmp = a->next;
	while(a->next != NULL)
	{
		tmp = a->next;
		while (tmp->next != NULL && a->number < tmp->number)
			tmp = tmp->next;
		if (tmp->next == NULL)
		{
			if (a->number < tmp->number)
				a = a->next;
			else
			{
				write(1, "KO\n", 3);
				return ;
			}
		}
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}

void	check_mov(t_data *data)
{
	char	*mov;
	t_stack	*a;
	t_stack	*b;

	a = get_stack_a(data);
	if (!a)
		return ;
	b = NULL;
	mov = get_next_line(0);
	while ((mov = get_next_line(0)))
	{
		find_mov(data, mov, &a, &b);
		free(mov);
	}
	free(mov);
	check_order(a);
	free_stack(&a);
	free_stack(&b);
}