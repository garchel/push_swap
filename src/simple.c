/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:06:40 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 05:04:11 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_list **stack_a, t_list **stack_b, int min, int next_min)
{
	t_list	*head;

	head = *stack_a;
	if (head->index == min && head->next->index != next_min)
	{
		swap(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			swap(stack_a, stack_b, 'a');
		else
			reverse_rotate(stack_a, stack_b, 'a');
	}
	else
	{
		if (head->next->index == min)
			rotate(stack_a, stack_b, 'a');
		else
		{
			swap(stack_a, stack_b, 'a');
			reverse_rotate(stack_a, stack_b, 'a');
		}
	}
}

static void	sort_3(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (verify_sorted(stack_a))
		return ;
	do_sort(stack_a, stack_b, min, next_min);
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
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

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (verify_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap(stack_a, stack_b, 'a');
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
