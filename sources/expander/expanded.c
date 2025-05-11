/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:00:58 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 21:12:17 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_dollar(char *str, size_t *i)
{
	size_t	start;
	char	*var;
	char	*env_val;

	(*i)++;
	if (ft_isdigit(str[*i]) || str[*i] == '@')
	{
		(*i)++;
		return (ft_strdup(""));
	}
	else if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(g_data.exit_s));
	}
	else if (!is_valid_var_char(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (is_valid_var_char(str[*i]))
		(*i)++;
	var = ft_substr(str, start, *i - start);
	env_val = get_envlst_value(var);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}

char	*cmd_pre_expand(char *str)
{
	char	*expanded;
	size_t	i;

	expanded = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			expanded = ft_strjoin_f(expanded, handle_squotes(str, &i));
		else if (str[i] == '"')
			expanded = ft_strjoin_f(expanded, handle_dquotes(str, &i));
		else if (str[i] == '$')
			expanded = ft_strjoin_f(expanded, handle_dollar(str, &i));
		else
			expanded = ft_strjoin_f(expanded, handle_normal_str(str, &i));
	}
	return (expanded);
}

char	**expand_args(char *str)
{
	char	**expanded;
	char	**globbed;
	size_t	i;

	str = cmd_pre_expand(str);
	if (!str)
		return (NULL);
	str = remove_empty_quotes(str);
	if (!str)
		return (NULL);
	expanded = expander_split(str);
	free(str);
	if (!expanded)
		return (NULL);
	globbed = globber(expanded);
	if (!globbed)
		return (NULL);
	i = 0;
	while (globbed[i])
	{
		globbed[i] = strip_quotes(globbed[i]);
		i++;
	}
	return (globbed);
}
