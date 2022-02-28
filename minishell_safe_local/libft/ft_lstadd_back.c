/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:17:54 by nkolle            #+#    #+#             */
/*   Updated: 2021/08/09 15:46:05 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ele;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			return ;
		}
		else
		{
			ele = ft_lstlast(*lst);
			ele->next = new;
		}
	}
}
