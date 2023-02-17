/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:06:29 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 04:21:24 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rotate(t_list **stack)
{
	t_list	*current_node;
	t_list	*next;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	current_node = *stack;
	next = current_node->next;
	last = ft_lstlast(*stack);
	last->next = current_node;
	current_node->next = NULL;
	*stack = next;
	return (0);
}

int	rotate(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		if (do_rotate(stack_a) == -1)
			return (-1);
		ft_putendl_fd("ra", 1);
	}
	else if (flag == 'b')
	{
		if (do_rotate(stack_b) == -1)
			return (-1);
		ft_putendl_fd("rb", 1);
	}
	else if (flag == 'r')
	{
		if (do_rotate(stack_a) == -1 || do_rotate(stack_b) == -1)
			return (-1);
		ft_putendl_fd("rr", 1);
	}
	return (0);
}
