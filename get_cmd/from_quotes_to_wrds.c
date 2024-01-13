/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_quotes_to_wrds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:25:44 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/05 14:24:37 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// count the nbr of valid char that we want to dup
int	len_delete_quotes(char *str, int len, int i)
{
	char	quote;

	quote = '0';
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && quote == '0')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
			{
				i++;
				len++;
			}
			if (str[i] && str[i] == quote)
				i++;
			quote = '0';
		}
		else
		{
			i++;
			len++;
		}
	}	
	return (len);
}

char	*cpy_pste_clean_line(char *str, char *dup, int i, int j)
{
	char	quote;

	quote = '0';
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && quote == '0')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				dup[j++] = str[i++];
			if (str[i] && str[i] == quote)
				i++;
			quote = '0';
		}
		else if (str[i])
			dup[j++] = str[i++];
	}
	dup[j] = '\0';
	return (dup);
}

// supress all of the extra quotes
// and return a clean string
char	*delete_quotes(char *str, int len)
{
	char	*dup;

	len = len_delete_quotes(str, 0, 0);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	dup = cpy_pste_clean_line(str, dup, 0, 0);
	return (dup);
}

// check si il y a des quotes a supp
int	there_is_quotes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

// Changement, fonctionnement en str au lieu de array
char	*from_quotes_to_wrds(char *str)
{
	char	*s_tmp;

	if (!str)
		return (NULL);
	if (there_is_quotes(str) == 1)
	{
		s_tmp = str;
		str = delete_quotes(str, 0);
		s_tmp = ft_free_str(s_tmp);
	}
	return (str);
}

/*int	main(int argc, char **argv)
{
	char	**tab = NULL;
	int		i = 0;

	(void)	argc;
	tab = from_quotes_to_wrds(argv + 1);
	while (tab[i])
	{
		printf ("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	printf ("%s\n", tab[i]);
	free(tab[i]);
	return (0);
}*/
