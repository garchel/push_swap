/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:04:16 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/13 21:07:59 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int verify_sorted(t_list **stack)
{
	t_list *current_node;

	current_node = *stack;
	while (current_node && current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

int	get_distance(t_list **stack, int index)
{
	t_list	*current_node;
	int		distance;

	distance = 0;
	current_node = *stack;
	while (current_node)
	{
		if (current_node->index == index)
			break ;
		distance++;
		current_node = current_node->next;
	}
	return (distance);
}

void make_node_top(t_list **stack_a, t_list **stack_b, int node_distance)
{
	t_list	*current_node;
	int		list_size;
	int		distance_to_end;

	current_node = *stack_a;
	list_size = ft_lstsize(current_node);
	distance_to_end = list_size - node_distance;
	if (node_distance == 0)
		return;
	if (node_distance <= (list_size / 2))
	{
		while (node_distance-- > 0)
			rotate(stack_a, stack_b, 'a');
	}
	else
	{
		while (distance_to_end-- > 0)
			reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	free_stack(t_list **stack)
{
	t_list	*current_node;
	t_list	*holder;

	current_node = *stack;
	while (current_node)
	{
		holder = current_node;
		current_node = current_node->next;
		free(holder);
	}
	free(stack);
}
