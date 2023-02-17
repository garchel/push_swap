/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:06:40 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 06:20:31 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack, int val)
{
	t_list	*node;
	int		min;

	node = *stack;
	min = node->index;
	while (node->next)
	{
		node = node->next;
		if ((node->index < min) && node->index != val)
			min = node->index;
	}
	return (min);
}

void	do_sort(t_list **stack_a, t_list **stack_b, int min, int next_min)
{
	t_list	*node;

	node = *stack_a;
	if (node->index == min && node->next->index != next_min)
	{
		swap(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	else if (node->index == next_min)
	{
		if (node->next->index == min)
			swap(stack_a, stack_b, 'a');
		else
			reverse_rotate(stack_a, stack_b, 'a');
	}
	else
	{
		if (node->next->index == min)
			rotate(stack_a, stack_b, 'a');
		else
		{
			swap(stack_a, stack_b, 'a');
			reverse_rotate(stack_a, stack_b, 'a');
		}
	}
}

void	sort_3(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		min;
	int		next_min;

	node = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (verify_sorted(stack_a))
		return ;
	do_sort(stack_a, stack_b, min, next_min);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (verify_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate(stack_a, stack_b, 'a');
	else if (distance == 2)
	{
		rotate(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	else if (distance == 3)
		reverse_rotate(stack_a, stack_b, 'a');
	if (verify_sorted(stack_a))
		return ;
	push(stack_a, stack_b, 'b');
	sort_3(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate(stack_a, stack_b, 'a');
	else if (distance == 2)
	{
		rotate(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	else if (distance == 3)
	{
		reverse_rotate(stack_a, stack_b, 'a');
		reverse_rotate(stack_a, stack_b, 'a');
	}
	else if (distance == 4)
		reverse_rotate(stack_a, stack_b, 'a');
	if (verify_sorted(stack_a))
		return ;
	push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
}
