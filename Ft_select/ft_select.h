/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MrRobot <mimazouz@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:54:15 by MrRobot           #+#    #+#             */
/*   Updated: 2016/05/10 17:01:31 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <fcntl.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>

typedef struct		s_file
{
	char			*name;
	size_t			pos;
	size_t			size;
	size_t			select;
	size_t			underline;
}					t_file;

typedef struct		s_select
{
	t_list			*curs;
	t_list			*file;
	struct termios	term_update;
	struct termios	term_restore;
	struct winsize	win;
	char			buf[4];
	size_t			nb_file;
	size_t			col;
	size_t			line;
	size_t			max;
	size_t			top;
	size_t			bot;
	size_t			right;
	size_t			left;
	size_t			lev;
	int				fd;
}					t_select;

t_file				*ft_new_link(char *name, size_t pos);

t_select			*ft_get_struct(t_select *sel);

size_t				ft_return_msd(t_list *list);

void				ft_init_struct(t_select *sel);
void				ft_print_list(t_list *file, t_select *sel, size_t i);
void				ft_make_list(t_select *sel, char **argv);
void				ft_check_cmd(t_select *sel);
void				ft_read_key(t_select *sel);
void				ft_modif_term(t_select *sel);
void				ft_left(t_select *sel);
void				ft_left_top(t_select *sel);
void				ft_left_last(t_select *sel);
void				ft_right(t_select *sel);
void				ft_right_bottom(t_select *sel);
void				ft_right_first(t_select *sel);
void				ft_right_select(t_select *sel, int i);
void				ft_bottom(t_select *sel);
void				ft_bottom_top(t_select *sel);
void				ft_top(t_select *sel, t_list *ptr);
void				ft_top_bottom(t_select *sel);
void				ft_put_file(t_select *sel, int underline);
void				ft_put_curs(char *str, size_t size);
void				ft_select(t_select *sel);
void				ft_select_first(t_select *sel);
void				ft_select_bottom(t_select *sel);
void				ft_return(t_select *sel);
void				ft_reset_term(t_select *sel);
void				ft_delete(t_select *sel);
void				ft_delete_last(t_select *sel);
void				ft_delete_first(t_select *sel);
void				ft_modif_pos(t_list *curs);
void				ft_modif_struct(t_select *sel);
void				ft_free_data(void *del);
void				ft_deplace_curs(t_select *sel);
void				ft_esc(t_select *sel);
void				ft_delete_max(t_select *sel);
void				ft_get_new_win_size(t_select *sel);
void				ft_signal(void);
void				ft_signal_finish(int signal);

int					ft_get_fd(int test);
int					ft_puts(int c);
int					ft_error(int error);

#endif
