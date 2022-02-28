/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:54:19 by nmichael          #+#    #+#             */
/*   Updated: 2022/02/28 17:21:52 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

#include "./libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# define OPERATOR = -2
# define TOKEN = -3


typedef struct s_token
{
	char	*value;
	int		type;
	struct s_token	*next;
}	t_token;

void	save_line();

#endif
