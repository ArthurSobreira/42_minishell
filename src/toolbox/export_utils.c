/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:51:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/03 18:28:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ordened_values(char *key, int fd)
{
	t_var	*tmp;

	tmp = get_core()->env_vars;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			if (tmp->value)
				ft_printf_fd(fd, "declare -x %s=\"%s\"\n", tmp->key, tmp->value);
			else
				ft_printf_fd(fd, "declare -x %s\n", tmp->key);
			return ;
		}
		tmp = tmp->next;
	}
}

char	*return_key(char *str)
{
	size_t	i;
	char	*key;

	i = 0;
	if (str[i] && str[i] != '=')
		i++;
	else
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (ft_strdup(str));
	key = ft_calloc(i + 1, sizeof(char));
	if (!key)
		ft_error("export: malloc failed", 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	return (key);
}

char	*return_value(char *str)
{
	size_t	i;
	size_t	j;
	char	*value;

	i = 0;
	if (ft_strchr(str, '=') == NULL)
		return (NULL);
	while (str[i] && str[i] != '=')
		i++;
	i++;
	j = i;
	while (str[j])
		j++;
	value = ft_calloc(j - i + 1, sizeof(char));
	if (!value)
		ft_error("export: malloc failed", 1);
	j = 0;
	while (str[i])
		value[j++] = str[i++];
	return (value);
}

void	add_end_var(t_var **var, t_var *new_var)
{
	t_var	*tmp;

	if (!*var)
	{
		*var = new_var;
		return ;
	}
	tmp = *var;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_var;
}

t_bool	is_valid_argument(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
		{
			if (arg[i] == '=')
				break ;
			ft_putendl_fd("export: not a valid identifier", STDERR_FILENO);
			get_core()->exit_status = EXIT_FAILURE;
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
