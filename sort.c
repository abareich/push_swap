/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:10:33 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:23:10 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_pile *pile)
{
	if (pile->top < 1)
		return ;
	if (pile->tableau[0] < pile->tableau[1])
		sa(pile);
}

void	sort_3(t_pile *pile)
{
	int	a;
	int	b;
	int	c;

	if (pile->top < 2)
		return ;
	a = pile->tableau[pile->top];
	b = pile->tableau[pile->top - 1];
	c = pile->tableau[pile->top - 2];
	if (a > b && b > c)
	{
		sa(pile);
		rra(pile);
	}
	else if (a > c && c > b)
		ra(pile);
	else if (b > a && a > c)
		rra(pile);
	else if (b > c && c > a)
	{
		sa(pile);
		ra(pile);
	}
	else if (c > a && a > b)
		sa(pile);
}

void	sort_5(t_pile *pile_a, t_pile *pile_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pivoter_vers_valeur(pile_a, trouver_min(pile_a));
		pb(pile_a, pile_b);
		i++;
	}
	if (pile_a->top == 2)
		sort_3(pile_a);
	else
		sort_2(pile_a);
	while (pile_b->top >= 0)
		pa(pile_a, pile_b);
}

void	radix_sort(t_pile *pile_a, t_pile *pile_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	max_bits = obt_max_bits(pile_a);
	size = pile_a->top + 1;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (obt_position_bit(pile_a->tableau[pile_a->top], i))
				ra(pile_a);
			else
				pb(pile_a, pile_b);
			j++;
		}
		while (pile_b->top >= 0)
			pa(pile_a, pile_b);
		i++;
	}
}

void	sort(t_pile *pile_a, t_pile *pile_b)
{
	if (is_sorted(pile_a))
		return ;
	rank_pile(pile_a);
	if (pile_a->top == 1)
		sort_2(pile_a);
	else if (pile_a->top == 2)
		sort_3(pile_a);
	else if (pile_a->top <= 4)
		sort_5(pile_a, pile_b);
	else
		radix_sort(pile_a, pile_b);
}
