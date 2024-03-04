/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:53 by phenriq2          #+#    #+#             */
/*   Updated: 2024/03/03 18:31:25 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	matrix_build(t_var *var, int fd)
{
	char	**sorted_vars;
	t_var	*current;
	size_t	i;

	i = 0;
	current = var;
	sorted_vars = ft_calloc(get_core()->env_vars_size + 1, sizeof(char *));
	if (!sorted_vars)
		ft_error("export: malloc failed", 1);
	while (current)
	{
		sorted_vars[i] = current->key;
		current = current->next;
		i++;
	}
	sorted_vars[i] = NULL;
	insert_sort(sorted_vars, fd);
	free(sorted_vars);
}

t_bool	set_value_on_existing_key(char *key, char *value)
{
	t_var	*tmp;

	tmp = get_core()->env_vars;
	if (!key)
		return (FALSE);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			if (!value)
				tmp->value = NULL;
			else
				tmp->value = ft_strdup(value);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

static void	process_arguments(t_cmd *command)
{
	size_t	i;
	char	*key;
	char	*value;

	i = 0;
	get_core()->exit_status = EXIT_SUCCESS;
	while (++i < ft_matrix_len(command->args))
	{
		if (!is_valid_argument(command->args[i]))
			return ;
		key = return_key(command->args[i]);
		value = return_value(command->args[i]);
		if (!set_value_on_existing_key(key, value))
		{
			add_end_var(&get_core()->env_vars, create_var(key, value));
			get_core()->env_vars_size++;
		}
		free(key);
		free(value);
	}
}

void	export_variables(t_cmd *command)
{
	int	fd_out;

	fd_out = STDOUT_FILENO;
	if (command->redir_out)
		fd_out = command->redir_out->fd_out;
	if (ft_matrix_len(command->args) == 1)
		matrix_build(get_core()->env_vars, fd_out);
	else
		process_arguments(command);
}
