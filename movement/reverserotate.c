/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:19:20 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/09 18:19:20 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int do_reverse_rotate(t_list **stack)
{
	t_list *current_node;
	t_list *last_node;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	current_node = *stack;
	last_node = ft_lstlast(current_node);
	while (current_node)
	{
		if (current_node->next->next == NULL)
		{
			 current_node->next = NULL;
			 break ;
		}
		current_node = current_node->next;
	}
	last_node->next = *stack;
	*stack = last_node;
	return (0);
}

int reverse_rotate(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		if (do_reverse_rotate(stack_a) == -1)
			return (-1);
		ft_putendl_fd("rra", 1);
	}
	else if (flag == 'b')
	{
		if (do_reverse_rotate(stack_b) == -1)
			return (-1);
		ft_putendl_fd("rrb", 1);
	}
	else if (flag == 'r')
	{
		if (do_reverse_rotate(stack_a) == -1 || do_reverse_rotate(stack_b) == -1)
			return (-1);
		ft_putendl_fd("rrr", 1);
	}
	return (0);
}