/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 08:29:19 by MrRobot           #+#    #+#             */
/*   Updated: 2016/11/29 17:02:47 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# define TYPE_C 1
# define TYPE_P 2
# define TYPE_V 3
# define ER_CMD "21sh: Command not found: "
# define ER_HOME ": Can't change to home directory."
# define ER_PERM "21sh: Permission denied: "
# define ER_ARG ": Error in your arguments."
# define ER_CD "21sh: No such file or directory: "
# define ER_ENV "env: Invalid argument: "
# define ER_SETENV "setenv: Variable name contain '=' character."
# define ER_EXEC "21sh: The file is not an executable."
# define ER_PARSE "21sh: Parse error near separator."
# define ER_SEG "21sh: Segmentation fault: "
# define ER_KILL "21sh: Terminated: "
# define ER_REDIR "21sh: Ambiguous redirect."
# define ER_TERM "21sh: Error no TERM variable"
# define ER_PWD "cd: No set: "
# define ER_DIR "cd: Not a directory: "

# include <libft.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <fcntl.h>
# include <dirent.h>

typedef struct		s_env
{
	char			*var;
	char			*val;
}					t_env;

typedef	struct		s_char
{
	char			c;
	int				under;
}					t_char;

typedef struct		s_copy
{
	t_list			*start;
	t_list			*curs;
}					t_copy;

typedef	struct		s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	char			*cmd;
	char			type;
}					t_tree;

typedef struct		s_line
{
	t_tree			*cmd;
	t_list			*start;
	t_list			*curs;
	t_copy			copy;
	struct winsize	win;
	int				left;
}					t_line;

typedef	struct		s_his
{
	t_list			*start;
	t_list			*curs;
	int				go;
	int				left;

}					t_his;

typedef	struct		s_fd
{
	int				fd;
	int				stdin;
	int				stderr;
	int				stdout;
}					t_fd;

typedef struct		s_tab
{
	char			*path;
	char			*file;
	char			*abrvt;
	struct dirent	*strc;
	DIR				*doss;
}					t_tab;

typedef	struct		s_shell
{
	t_list			*env;
	t_his			his;
	t_line			line;
	t_fd			fd;
	t_tab			tab;
	struct termios	term_restore;
}					t_shell;

extern	t_shell		g_shell;

t_tree				*ft_new_link_tree(void);
t_tree				*ft_build_tree(char *cmd);

t_char				*ft_new_link_line(char c);

t_env				*ft_new_link_env(char *str);
t_env				*ft_new_link_setenv(char *var, char *val);

t_list				*ft_env_in_list(char **env);
t_list				*ft_copy_line(t_list *start);

char				*ft_set_var_dollars(char *str, int i);
char				*ft_treat_dollars(char *str, int *i);
char				*ft_treat_special_char(char *str);
char				*ft_treat_tilde(char *str, int *i);
char				*ft_read_dir(t_tab *tab);
char				*ft_set_file(char *str, int i);
char				*ft_set_file_tab(char *cmd);
char				*ft_remove_quote_str(char *str);
char				**ft_remove_quote_tab(char **tab);
char				*ft_strtrim_separator(char *str);
char				*ft_set_path(char **tab, t_list *env);
char				*ft_set_path_tab(char *cmd);
char				*ft_path_env(char *cmd, t_list *env);
char				*ft_return_path(char *chr, t_list *env);
char				**ft_strsplit_space(char *str);
char				**ft_list_in_env(t_list *env_list);
char				*ft_list_in_line(t_list *start);

void				ft_jump_quote(char *str, int *i);
void				ft_copy_file_tab(t_line *line, char *path, char *file);
void				ft_free_tabulation(t_tab *tab);
void				ft_tabulation(t_line *line, t_tab *tab);
void				ft_echo(char **tab);
void				ft_heredoc(char *str, int i);
void				ft_line_parenthesis(t_line *line, t_his *his);
void				ft_dup_fd(t_fd *fd);
void				ft_close_fd(t_fd *fd);
void				ft_fork(char **tab, char *path, t_list *env);
void				ft_return(t_line *line, t_his *his, t_list **env);
void				ft_check_touch(t_line *line, t_his *his, char *buf);
void				ft_free_env(void *del);
void				ft_ignore_quote(char *str, int *i);
void				ft_init_new_line(t_line *new_line);
void				ft_dispatch_cmd(t_tree *tree, t_list **env);
void				ft_no_fork(char *str, t_list **env);
void				ft_treat_cmd(char *str, t_list **env);
void				ft_treat_pipe(t_tree *tree, t_list **env);
void				ft_tree_del_all(t_tree **tree);
void				ft_init_struct(t_shell *shell);
void				ft_signal(int test);
void				ft_signal_2(int status, char *path);
void				ft_go_cmd(t_line *line, t_his *his, t_list **env);
void				ft_change_path(char *var, char *new_val, t_list *env);
void				ft_exit(struct termios *term_restore, int test);
void				ft_up(t_line *line);
void				ft_down(t_line *line);
void				ft_paste_copy(t_line *line);
void				ft_cut_select(t_line *line);
void				ft_select_in_line(t_line *line);
void				ft_free_cut(t_line *line, t_list **ptr);
void				ft_copy_select(t_line *line);
void				ft_word_right(t_line *line);
void				ft_word_left(t_line *line);
void				ft_list_in_his(t_his *his, t_list *start);
void				ft_delete(t_line *line);
void				ft_insert_char(t_line *line);
void				ft_21sh(t_shell *shell);
void				ft_modif_term(struct termios *term_set, int test);
void				ft_print_env(t_list *env);
void				ft_line_in_list(t_line *line, char c);
void				ft_put_curs(t_line *line);
void				ft_right(t_line *line);
void				ft_left(t_line *line);
void				ft_history_top(t_his *his, t_line *line);
void				ft_history_bottom(t_his *his, t_line *line);
void				ft_print_prompt(int test);
void				ft_end(t_line *line);
void				ft_home(t_line *line);
void				ft_free(void *del);

int					ft_change_fd(char c, int test, int fd);
int					ft_check_valid_redirect(char *str);
int					ft_dispatch_redirection(char *str);
int					ft_redirect(char *str, t_list **env, int test);
int					ft_chr_redirect(char *str);
int					ft_check_builtins(t_list **env, char **tab);
int					ft_put_parenthesis(char c);
int					ft_check_close_quote(t_list *curs, char c);
int					ft_check_close_parenthesis(t_list *curs, char c);
int					ft_check_parenthesis(t_list *start);
int					ft_check_setenv(char **tab, t_list **env);
int					ft_setenv(t_list **env, char *var, char *val);
int					ft_unsetenv(t_list **env, char *var);
int					ft_cd(t_list *env, char **tab);
int					ft_env(char **tab, t_list *env);
int					ft_check_cut(t_list *start);
int					ft_put_line(t_list *curs);
int					ft_curs_pos_row(int fd);
int					ft_curs_pos_col(int fd);
int					ft_put(int c);
int					ft_error(char *error, char *str);
int					ft_find_separator(char *cmd, char c, int test);
int					ft_check_aggregations(char *str, int i, int test);
int					ft_open_fd(char *str, int j, char c, int test);
int					ft_count_redirect(char *str, int *i);
int					ft_isquote(char c);

#endif
