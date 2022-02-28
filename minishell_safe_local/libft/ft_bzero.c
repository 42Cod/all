/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:50:08 by nkolle            #+#    #+#             */
/*   Updated: 2021/08/13 12:02:56 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = s;
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
}