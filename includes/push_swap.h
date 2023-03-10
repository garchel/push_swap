/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:23:46 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 06:24:55 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

//List functions
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
int		ft_lstsize(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);

//Movement functions
int		reverse_rotate(t_list **stack_a, t_list **stack_b, char flag);
int		rotate(t_list **stack_a, t_list **stack_b, char flag);
int		push(t_list **stack_to, t_list **stack_from, char flag);
int		swap(t_list **stack_a, t_list **stack_b, char flag);

//Src functions
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a, t_list **stack_b);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);

//Utils functions
void	verify_input_args(int argc, char **argv);
void	index_nodes(t_list **stack);
void	free_stack(t_list **stack);
int		get_distance(t_list **stack, int index);
int		verify_sorted(t_list **stack);
void	ft_free(char **str);
void	ft_error(char *msg);

#endif