/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:12:05 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 04:18:30 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_next_lower(t_list **stack)
{
	t_list	*current_node;
	t_list	*min;
	int		has_min;

	current_node = *stack;
	min = NULL;
	has_min = 0;
	while (current_node)
	{
		if (current_node->index == -1
			&& (!has_min || current_node->value < min->value))
		{
			min = current_node;
			has_min = 1;
		}
		current_node = current_node->next;
	}
	return (min);
}

void	index_nodes(t_list **stack)
{
	t_list	*current_node;
	int		index;

	index = 0;
	current_node = find_next_lower(stack);
	while (current_node)
	{
		current_node->index = index++;
		current_node = find_next_lower(stack);
	}
}
