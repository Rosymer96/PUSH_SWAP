/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:27:08 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 22:43:21 by albben-a         ###   ########.fr       */
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
	if (ft_strncmp(mov, "ra\n", 3) == 0)
		ra(a, data);
	else if (ft_strncmp(mov, "rb\n", 3) == 0)
		rb(b, data);
	else if (ft_strncmp(mov, "rr\n", 3) == 0)
		rr(a, b, data);
	else if (ft_strncmp(mov, "rra\n", 4) == 0)
		rra(a, data);
	else if (ft_strncmp(mov, "rrb\n", 4) == 0)
		rrb(b, data);
	else if (ft_strncmp(mov, "rrr\n", 4) == 0)
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
	if (ft_strncmp(mov, "sa\n", 3) == 0)
		sa(*a, data);
	else if (ft_strncmp(mov, "sb\n", 3) == 0)
		sb(*b, data);
	else if (ft_strncmp(mov, "ss\n", 3) == 0)
		ss(*a, *b, data);
	else if (ft_strncmp(mov, "pa\n", 3) == 0)
		pa(a, b, data);
	else if (ft_strncmp(mov, "pb\n", 3) == 0)
		pb(a, b, data);
	else
		continue_find_mov(data, mov, a, b);
}

static int	check_order(t_stack *a)
{
	while (a && a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
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
	while (mov)
	{
		find_mov(data, mov, &a, &b);
		free(mov);
		mov = get_next_line(0);
	}
	if (check_order(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
}
