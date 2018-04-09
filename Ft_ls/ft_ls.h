/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 12:27:53 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/10 08:37:16 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

typedef	struct		s_size
{
	unsigned long	nb_link;
	unsigned long	pw_name;
	unsigned long	gr_name;
	unsigned long	nb_octet;
	unsigned long	majeur;
	unsigned long	mineur;
	unsigned long	size_h;
	unsigned long	nb_block;
	size_t			p;
}					t_size;

typedef	struct		s_path
{
	char			*content;
	struct stat		t;
	struct s_path	*next;
}					t_path;

typedef struct		s_flags
{
	short			l;
	short			r;
	short			gr;
	short			a;
	short			t;
	short			f;
	short			p;
	short			s;
	int				option;
	int				road;
	int				argc;
	t_path			*file;
	t_path			*rep;
	t_size			size;
	long			(*cmp)(t_path *, t_path *);
}					t_flags;

void				ft_read_dirr(char *name, t_flags *flags);
void				ft_treat_path(t_flags *flags, char **argv, int i);
void				ft_treat_path_2(t_flags *flags);
void				ft_initialise_struct(t_flags *flags, int argc);
void				ft_no_path(int argc, char **argv);
void				ft_error_2(char *name, int k);
void				ft_one_path(t_flags *flags);
void				ft_initialise_cmp(t_flags *flags);
void				ft_check_fake_path(t_flags *flags, char **argv, int i);
void				ft_make_all(char *file, t_flags *flags, t_path **all,
					char *name);
void				ft_print_nb_link(t_flags *flags, t_path *file);
void				ft_print_octet(t_flags *flags, t_path *file);
void				ft_print_date(t_path *file);
void				ft_print_link(t_flags *flags, t_path *file, char *name);
void				ft_print_law_usr(t_flags *flags, t_path *file);
void				ft_print_law_grp(t_flags *flags, t_path *file);
void				ft_print_law_oth(t_flags *flags, t_path *file);
void				ft_print_file(t_path *file, t_flags *flags,
					int i, char *name);
void				ft_recursive(char *name, t_flags *flags, t_path **list);
void				ft_initialise_first_all(t_flags *flags, t_path **all);
void				ft_init_size(t_flags *flags, t_path *ptr);
void				ft_print_colors(t_flags *flags, t_path *file,
					char *name, char *str);
void				ft_free_lst(t_path **file);
void				ft_print_usr(struct passwd *info, t_path *file,
					t_flags *flags);
void				ft_print_grp(struct group *info_gr, t_path *file,
					t_flags *flags);
void				ft_print_mam(t_path *file, t_flags *flags);
void				ft_print_mam_2(t_path *file, t_flags *flags);
void				ft_print_mam_3(t_path *file, t_flags *flags);
void				ft_print_link_2(t_flags *flags, t_path *link, char *name);
void				ft_norminette(char **tmp, char **tmp_2, t_path **ptr,
					char *file);
void				ft_norminette_2(t_flags *flags, t_path **all);
void				ft_norminette_3(t_flags *flags, t_path *ptr);

size_t				ft_init_count(t_path *file, int k);

int					ft_fill_option(t_flags *flags, char **argv, int i, int *j);
int					ft_error(char c);
int					ft_read_argv(t_flags *flags, char **argv);

long				ft_cmp_alpha(t_path *file, t_path *link);
long				ft_cmp_reverse(t_path *file, t_path *link);
long				ft_cmp_time(t_path *file, t_path *link);
long				ft_cmp_time_and_reverse(t_path *file, t_path *link);
long				ft_cmp_f(t_path *file, t_path *link);

t_path				*ft_creat_elem(char *file, t_flags *flags, t_path **all,
					char *name);

#endif
