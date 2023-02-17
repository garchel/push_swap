/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:47:47 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 18:26:26 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_swap(t_list **stack)
{
	t_list	*current_node;
	t_list	*next;
	int		holder_val;
	int		holder_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	current_node = *stack;
	next = current_node->next;
	if (!current_node && !next)
		ft_error("Error");
	holder_val = current_node->value;
	holder_index = current_node->index;
	current_node->value = next->value;
	current_node->index = next->index;
	next->value = holder_val;
	next->index = holder_index;
	return (0);
}

int	swap(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		if (do_swap(stack_a) == -1)
			return (-1);
		ft_putendl_fd("sa", 1);
	}
	else if (flag == 'b')
	{
		if (do_swap(stack_b) == -1)
			return (-1);
		ft_putendl_fd("sb", 1);
	}
	else if (flag == 's')
	{
		if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
			return (-1);
		do_swap(stack_a);
		do_swap(stack_b);
		ft_putendl_fd("ss", 1);
	}
	return (0);
}
