/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:46:29 by mimazouz          #+#    #+#             */
/*   Updated: 2017/01/25 15:21:07 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# define BLUE "\033[1;34m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define STOP "\033[0;0m"
# include <ft_printf.h>

typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	void			*data;
}					t_list;

typedef struct		s_get
{
	char			*save;
	char			buff[BUFF_SIZE + 1];
	int				fd;
	struct s_get	*next;
}					t_get;

t_list				*ft_list_add_new(void *data);

void				ft_putnchar(char c, size_t size);
void				ft_putnchar_fd(char c, size_t size, int fd);
void				ft_list_del_last(t_list **list, void (*f)(void *data));
void				ft_list_del_last_one(t_list **list, void (*f)(void *data));
void				ft_list_del_all(t_list **list, void (*f)(void *data));
void				ft_list_del_first(t_list **list, void (*f)(void *data));
void				ft_list_del(t_list *del, void (*f)(void *data));
void				ft_go_to_first(t_list **list);
void				ft_go_to_last(t_list **list);
void				ft_list_add_last(t_list *list, void *data);
void				ft_list_add_first(t_list **list, void *data);
void				ft_list_add_before(t_list **curs, t_list **new);
void				ft_list_add_after(t_list **curs, t_list **new);
void				ft_free_tab(char **tab);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_bl(intmax_t n, unsigned int base);
void				ft_putnbr_bul(uintmax_t n, unsigned int base);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_puttab(char **tab, char c);
void				ft_puttab_fd(char **tab, char c, int fd);
void				ft_strclr(char *s, size_t n);
void				ft_strdel(char **as);
void				ft_replace_char(char *str, char c, char replace);

char				*ft_str_add_str_index(char *str, char *insert, int i);
char				*ft_str_add_index(char *str, char c, int i);
char				*ft_str_add_last(char *str, char c);
char				*ft_str_add_first(char *str, char c);
char				*ft_tabstr(char **tab);
char				**ft_strtab(char *str);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, const char *s2);
char				*ft_itoa_bl(intmax_t n, unsigned int base);
char				*ft_itoa_bul(uintmax_t n, unsigned int base);
char				**ft_strsplit(char const *s, char c);
char				**ft_tabnew(size_t size);
char				**ft_tabdup(char **tab);
char				**ft_tab_add_last(char **tab, char *add);
char				**ft_tab_add_first(char **tab, char *add);
char				**ft_tabjoin(char **tab1, char **tab2);

int					ft_printf(char const *format, ...);
int					ft_get_next_line(int const fd, char **line);
int					ft_strchri(char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					*ft_intnew(size_t n);
int					ft_count_words(char const *s, char c);

intmax_t			ft_count_cbl(intmax_t n, unsigned int base);

uintmax_t			ft_count_cbul(uintmax_t n, unsigned int base);

long				ft_power(long nb, long power);

size_t				ft_list_size(t_list *list);
size_t				ft_strlen(const char *str);
size_t				ft_tablen(char **tab);

#endif
