/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:26:11 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/10 08:35:42 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <sys/param.h>

typedef struct		s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env				*ft_make_list(char *str);
t_env				*ft_make_setenv(char *var, char *value);

void				ft_exec_minishell(char *line, int argc, t_env *env_list);
void				ft_signal(int sig);
void				ft_signal_2(int sig);
void				ft_change_path(char *var, char *new_value, t_env *env);
void				ft_free_list(t_env **env);
void				ft_print_list(t_env *env);
void				ft_env_in_list(t_env **env_list, char **env);
void				ft_change_var_env(char **tab, t_env **env, int i, int j);
void				ft_exec_env(char **envnt, char **tab, t_env **env, int i);

char				*ft_return_path(char *chr, t_env *env);
char				**ft_list_in_env(t_env *env_list);
char				*ft_other_path(char *cmd, t_env *env);

int					ft_fork(char *path, char **tab, char **environ);
int					ft_check_command(t_env **env, char **tab);
int					ft_exec_cmd(char **tab, t_env *env);
int					ft_cd(t_env *env, char **tab);
int					ft_parsing_cd(t_env *env, char **tab);
int					ft_check_path_cd(t_env *env, int i, char **tab);
int					ft_cd_less(t_env *env);
int					ft_env(char **tab, t_env *env);
int					ft_env_u(char **tab, int *i, t_env **env);
int					ft_setenv(t_env **env, char *var, char *value);
int					ft_check_setenv(char **tab, t_env **env);
int					ft_unsetenv(t_env **env, char *var);
int					ft_unsetenv_one(t_env **env, char *var);
int					ft_error(int error, char *str);

#endif
