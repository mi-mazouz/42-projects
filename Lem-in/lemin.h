/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:09:47 by MrRobot           #+#    #+#             */
/*   Updated: 2016/09/22 15:28:39 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>

typedef	struct	s_name
{
	char		*name;
}				t_name;

typedef	struct	s_file
{
	t_list		*start;
	t_list		*curs;
}				t_file;

typedef struct	s_tab
{
	char		**tab;
}				t_tab;

typedef struct	s_pipe
{
	t_list		*curs;
	t_list		*start;
	t_list		*s_tab;
	t_list		*e_tab;
	char		*link;
	char		*occu;
	int			pipe;
}				t_pipe;

typedef	struct	s_room
{
	t_list		*start;
	t_list		*curs;
	t_list		*end;
	int			room;
}				t_room;

typedef	struct	s_lemin
{
	t_pipe		pipe;
	t_file		file;
	t_room		room;
	int			ant;
	int			p;
	int			h;
	int			c;
	int			n;
}				t_lemin;

t_name			*ft_new_link_name(char *name);
t_tab			*ft_new_link_tab(char **tab);

char			**ft_new_tab(char **tmp);
char			**ft_remove_tab(char **neigh, char **tmp, char *room);
char			**ft_treat_algo(t_pipe *pipe, t_room *room);
char			**ft_fill_path_end(t_pipe *pipe, t_list *s_tab, char **occu);
char			**ft_fill_path_start(t_pipe *pipe, t_list *s_tab, char **occu);
char			**ft_just_one_path(t_pipe *pipe, t_room *room);
char			*ft_set_common(char **s_neigh, char **e_neigh);
char			*ft_set_link(char **s_neigh, char **e_neigh, t_pipe *pipe);
char			**ft_set_neigh(t_list *start, char *room);
char			**ft_set_neigh_many_room(char **neigh, t_list *start);
char			*ft_set_link_start_end(t_pipe *pipe, t_room *room);
char			**ft_path(t_pipe *pipe, t_room *room, char *s_oc, char *e_oc);

void			ft_put_colors(int c, int ant, char *room);
void			ft_first_print(char **path, t_lemin *lemin, int *nbc);
void			ft_last_print(char **path, t_lemin *lemin, int *nbc);
void			ft_check_option(t_lemin *lemin, char **argv, int i);
void			ft_print_ant_course(char **path, t_lemin *lemin);
void			ft_list_add_name(t_list **start, t_list **curs, char *line);
void			ft_list_add_room(t_list **curs, char *line);
void			ft_print_file(t_list *start);
void			ft_list_add_tab(t_list **start, char **tab);
void			ft_init_struct(t_lemin *lemin);
void			ft_exit(void);

int				ft_room_exist(char *room, t_list *start);
int				ft_treat_data(t_lemin *lemin);
int				ft_check_line(t_lemin *lemin, char *line);
int				ft_check_dup(t_list *curs, char *chr);
int				ft_check_cmd(t_file *file, t_room *room, char *line);
int				ft_set_start_end(t_file *file, t_room *room, char *line, int t);
int				ft_set_room(t_room *room, t_pipe *pipe, char *line);
int				ft_set_pipe(t_pipe *pipe, t_room *room, char *line);
int				ft_chr_path(char **s_n, char **e_n, t_pipe *pipe, t_room *room);

#endif
