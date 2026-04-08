/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:09:59 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:10:01 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile *pile_a)
{
	int	temp;

	if (pile_a->top < 1)
		return ;
	temp = pile_a->tableau[pile_a->top];
	pile_a->tableau[pile_a->top] = pile_a->tableau[pile_a->top - 1];
	pile_a->tableau[pile_a->top - 1] = temp;
	write(1, "sa\n", 3);
}

void	ra(t_pile *pile_a)
{
	int	temp;
	int	i;

	if (pile_a->top < 1)
		return ;
	temp = pile_a->tableau[pile_a->top];
	i = pile_a->top;
	while (i > 0)
	{
		pile_a->tableau[i] = pile_a->tableau[i - 1];
		i--;
	}
	pile_a->tableau[0] = temp;
	write(1, "ra\n", 3);
}

void	rra(t_pile *pile_a)
{
	int	temp;
	int	i;

	i = 0;
	if (pile_a->top < 1)
		return ;
	temp = pile_a->tableau[0];
	while (i < pile_a->top)
	{
		pile_a->tableau[i] = pile_a->tableau[i + 1];
		i++;
	}
	pile_a->tableau[pile_a->top] = temp;
	write(1, "rra\n", 4);
}

void	pa(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->top < 0)
		return ;
	pile_a->top++;
	pile_a->tableau[pile_a->top] = pile_b->tableau[pile_b->top];
	pile_b->top--;
	write(1, "pa\n", 3);
}

void	pb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->top < 0)
		return ;
	pile_b->top++;
	pile_b->tableau[pile_b->top] = pile_a->tableau[pile_a->top];
	pile_a->top--;
	write(1, "pb\n", 3);
}
