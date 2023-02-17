/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:04:16 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 04:16:01 by pauvicto         ###   ########.fr       */
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

int	verify_sorted(t_list **stack)
{
	t_list	*current_node;

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
