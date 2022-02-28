/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:52:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/28 17:20:57 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_line(void)
{
	char	*line;
	char	**s_array;
	int		i;

	i = 0;
	line = NULL;
	line = readline("$");
	s_array = ft_split(line,  ' ');
	while(s_array[i])
	{
		printf("array = %s \n", s_array[i]);
		i++;
	}

}

int	main(void)
{
	save_line();

	return(0);
}