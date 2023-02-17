/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:56:47 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 06:18:07 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*current_node;
	int		max;
	int		max_bits;

	current_node = *stack;
	max = current_node->index;
	max_bits = 0;
	while (current_node)
	{
		if (current_node->index > max)
			max = current_node->index;
		current_node = current_node->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_node;
	int		bits_counter;
	int		node_counter;
	int		size;
	int		max_bits;

	bits_counter = 0;
	current_node = *stack_a;
	size = ft_lstsize(current_node);
	max_bits = get_max_bits(stack_a);
	while (bits_counter < max_bits)
	{
		node_counter = 0;
		while (node_counter++ < size)
		{
			current_node = *stack_a;
			if (((current_node->index >> bits_counter) & 1) == 1)
				rotate(stack_a, stack_b, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (ft_lstsize(*stack_b) != 0)
			push(stack_a, stack_b, 'a');
		bits_counter++;
	}
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
