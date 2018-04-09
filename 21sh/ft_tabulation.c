/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:16:12 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/23 18:53:02 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_tabulation(t_line *line, t_tab *tab)
{
	char			*tmp;
	char			*cmd;
	int				i;

	i = 0;
	if (line->start == NULL || line->curs->next != NULL)
		return ;
	cmd = ft_list_in_line(line->start);
	tab->path = ft_set_path_tab(cmd);
	if ((tab->doss = opendir(tab->path)) == NULL)
	{
		free(tab->path);
		free(cmd);
		return ;
	}
	tab->abrvt = ft_set_file_tab(cmd);
	if ((tab->file = ft_read_dir(tab)) != NULL)
	{
		tmp = ft_strjoin(tab->path, tab->file);
		ft_copy_file_tab(line, tmp, &tab->file[ft_strlen(tab->abrvt)]);
	}
	ft_free_tabulation(tab);
}

char	*ft_read_dir(t_tab *tab)
{
	int		i;
	int		j;

	j = 0;
	while ((tab->strc = readdir(tab->doss)) != NULL)
	{
		i = 0;
		while (tab->abrvt[i] != 0 && tab->strc->d_name[i] == tab->abrvt[i])
			i++;
		if (tab->abrvt[i] == 0 && j++ == 0)
			tab->file = ft_strdup(tab->strc->d_name);
		else if (tab->abrvt[i] == 0 && j == 2)
		{
			free(tab->file);
			tab->file = NULL;
			closedir(tab->doss);
			return (NULL);
		}
	}
	closedir(tab->doss);
	return (tab->file);
}

void	ft_copy_file_tab(t_line *line, char *path, char *file)
{
	struct stat	info;

	while (*file != 0)
	{
		ft_putchar_fd(*file, g_shell.fd.stdout);
		ft_line_in_list(line, *file);
		file++;
	}
	if (lstat(path, &info) != -1 && S_ISDIR(info.st_mode) == 1)
	{
		ft_putchar_fd('/', g_shell.fd.stdout);
		ft_line_in_list(line, '/');
	}
	free(path);
}

char	*ft_set_path_tab(char *cmd)
{
	char	*path;
	int		j;
	int		i;

	i = ft_strlen(cmd);
	while (cmd[i] != '/')
	{
		if (cmd[i] == ' ' || i == 1)
			return (ft_strdup("./"));
		i--;
	}
	j = i;
	while (i != 0 && cmd[i - 1] != ' ')
		i--;
	path = ft_strsub(cmd, i, j - (i - 1));
	return (path);
}

char	*ft_set_file_tab(char *cmd)
{
	char	*file;
	int		i;

	i = ft_strlen(cmd);
	while (i != 0 && cmd[i - 1] != ' ' && cmd[i - 1] != '/')
		i--;
	file = ft_strsub(cmd, i, ft_strlen(cmd) - i);
	free(cmd);
	return (file);
}
