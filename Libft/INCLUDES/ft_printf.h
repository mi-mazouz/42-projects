/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:27:54 by mimazouz          #+#    #+#             */
/*   Updated: 2016/03/31 16:39:02 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_printf
{
	char		*flags;
	char		*frmt;
	char		letter;
	int			l;
	int			h;
	int			j;
	int			z;
	int			htag;
	int			zero;
	int			moins;
	int			plus;
	int			space;
	int			width;
	int			preci;
	int			point;
	int			i;
	int			m;
	int			k;
	int			o;
}				t_printf;

int				g_octet;

char			*ft_masks_unicode(char *str);

void			ft_check_flags(t_printf *block);
void			ft_check_flags_1(t_printf *block, int i, int *zero);
void			ft_check_flags_2(t_printf *block, int i);
void			ft_check_flags_3(t_printf *block, int i, int *p, int *zero);
void			ft_check_flags_4(t_printf *block, int i, int *pass, int *zero);
void			ft_result_letter_percent_2(t_printf *link, int *j, int i);
void			ft_conv_wchar(wchar_t value);
void			ft_conv_decimal(char *str);
void			ft_conv_decimal_1(char *tab, int i);
void			ft_conv_decimal_2(char *tab, int i);
void			ft_conv_decimal_3(char *tab, int i);
void			ft_conv_decimal_4(char *tab, int i);
void			ft_fill_masks(char *str, char *tab);
void			ft_fill_tab(char **tab, int i);
void			ft_putint(int c);
void			ft_putnbr_base_unsigned_long(unsigned long n,
				unsigned int base);
void			ft_initialize_flags(t_printf *link);
void			ft_treat_block_2(t_printf *block, int test);

int				ft_return_octet(int p);
int				ft_check_numbers_flags(t_printf *b);
int				ft_check_all_block(char const *format, int i, int j,
				t_printf block);
int				ft_treat_block(t_printf block, int j, va_list ap);
int				ft_check_block(char const *format, t_printf *block, int i,
				int j);
int				ft_check_order_flags(t_printf *b);
int				ft_check_order_flags_2(t_printf *b, int *flags, int i);
int				ft_verif(char *str, char c);
int				ft_check_char(char c);
int				ft_check_char_2(char c);
int				ft_check_char_3(char c);
int				ft_check_char_4(char c);
int				ft_check_char_5(char c);
int				ft_t_block(t_printf *link, va_list ap);
int				ft_nb_octet(char *str);
int				ft_check_letter(t_printf *link, va_list ap);
int				ft_check_letter_2(t_printf *link, va_list ap);
int				ft_result_letter_c(t_printf *link, va_list ap);
int				ft_result_letter_tall_c(t_printf *link, va_list ap);
int				ft_result_letter_p(t_printf *link, va_list ap);
int				ft_result_letter_percent(t_printf *link);

long			ft_return_type(t_printf *link, va_list ap);

unsigned long	ft_return_type_u(t_printf *link, va_list ap);

int				ft_result_letter_x(t_printf *link, va_list ap);
void			ft_result_letter_x_1(t_printf *link, unsigned long *p);
int				ft_result_letter_x_2(t_printf *link, unsigned long *p);
void			ft_result_letter_x_3(t_printf *link, unsigned long *p);
int				ft_result_letter_x_4(t_printf *link, unsigned long *p);
void			ft_result_letter_x_5(t_printf *link, unsigned long *p);
int				ft_result_letter_x_6(t_printf *link, unsigned long *p);
void			ft_result_letter_x_7(t_printf *link, unsigned long *p);
int				ft_result_letter_x_8(t_printf *link, unsigned long *p);
void			ft_result_letter_x_9(t_printf *link);
int				ft_result_letter_x_10(t_printf *link, unsigned long *p);
void			ft_result_letter_x_11(t_printf *link);
int				ft_result_letter_x_12(t_printf *link, unsigned long *p);
void			ft_result_letter_x_13(t_printf *link, unsigned long *p);
int				ft_result_letter_x_14(t_printf *link, unsigned long *p);
void			ft_result_letter_x_15(t_printf *link, unsigned long *p);
int				ft_result_letter_x_16(t_printf *link, unsigned long *p);
void			ft_result_letter_x_17(t_printf *link, unsigned long *p);

int				ft_result_letter_u(t_printf *link, va_list ap);
void			ft_result_letter_u_1(t_printf *link, unsigned long *p);
int				ft_result_letter_u_2(t_printf *link, unsigned long *p);
int				ft_result_letter_u_3(t_printf *link, unsigned long *p);
int				ft_result_letter_u_4(t_printf *link, unsigned long *p);
int				ft_result_letter_u_5(t_printf *link, unsigned long *p);
int				ft_result_letter_u_6(t_printf *link, unsigned long *p);
int				ft_result_letter_u_7(t_printf *link, unsigned long *p);
int				ft_result_letter_u_8(t_printf *link, unsigned long *p);
int				ft_result_letter_u_9(t_printf *link, unsigned long *p);

int				ft_result_letter_tall_s(t_printf *link, va_list ap);
int				ft_result_letter_tall_s_1(t_printf *link, wchar_t *s, int *p);
int				ft_result_letter_tall_s_2(t_printf *link, wchar_t *s, int *p);
int				ft_result_letter_tall_s_3(t_printf *link, wchar_t *s, int *p);
int				ft_result_letter_tall_s_4(t_printf *link, wchar_t *s, int *p);
int				ft_result_letter_tall_s_5(t_printf *link, wchar_t *s, int *p);
int				ft_result_letter_tall_s_6(t_printf *link, wchar_t *s, int *p);
void			ft_result_letter_tall_s_7(t_printf *link, wchar_t *s, int *p);

int				ft_result_letter_s(t_printf *link, va_list ap);
int				ft_result_letter_s_1(t_printf *link, char *str);
int				ft_result_letter_s_2(t_printf *link, char *str);
int				ft_result_letter_s_3(t_printf *link, char *str);
int				ft_result_letter_s_4(t_printf *link, char *str);
int				ft_result_letter_s_5(t_printf *link, char *str);

int				ft_result_letter_o(t_printf *link, va_list ap);
void			ft_result_letter_o_1(t_printf *link, unsigned long *p);
int				ft_result_letter_o_2(t_printf *link, unsigned long *p);
int				ft_result_letter_o_3(t_printf *link, unsigned long *p);
void			ft_result_letter_o_4(t_printf *link, unsigned long *p);
int				ft_result_letter_o_5(t_printf *link, unsigned long *p);
int				ft_result_letter_o_6(t_printf *link, unsigned long *p);
int				ft_result_letter_o_7(t_printf *link, unsigned long *p);
int				ft_result_letter_o_8(t_printf *link, unsigned long *p);
int				ft_result_letter_o_9(t_printf *link, unsigned long *p);
int				ft_result_letter_o_10(t_printf *link, unsigned long *p);

int				ft_result_letter_d(t_printf *link, va_list ap);
void			ft_result_letter_d_1(t_printf *link, long *p);
int				ft_result_letter_d_2(t_printf *link, long *p);
int				ft_result_letter_d_3(t_printf *link, long *p);
void			ft_result_letter_d_4(t_printf *link, long *p);
int				ft_result_letter_d_5(t_printf *link, long *p);
void			ft_result_letter_d_6(t_printf *link, long *p);
int				ft_result_letter_d_7(t_printf *link, long *p);
void			ft_result_letter_d_8(t_printf *link, long *p);
int				ft_result_letter_d_9(t_printf *link, long *p);
void			ft_result_letter_d_10(t_printf *link, long *p);
int				ft_result_letter_d_11(t_printf *link, long *p);
void			ft_result_letter_d_12(t_printf *link, long *p);
int				ft_result_letter_d_13(t_printf *link, long *p);
int				ft_result_letter_d_14(t_printf *link, long *p);
void			ft_result_letter_d_15(t_printf *link, long *p);

int				ft_result_letter_b(t_printf *link, va_list ap);
void			ft_result_letter_b_1(t_printf *link, long *p);
int				ft_result_letter_b_2(t_printf *link, long *p);
int				ft_result_letter_b_3(t_printf *link, long *p);
void			ft_result_letter_b_4(t_printf *link, long *p);
int				ft_result_letter_b_5(t_printf *link, long *p);
void			ft_result_letter_b_6(t_printf *link, long *p);
int				ft_result_letter_b_7(t_printf *link, long *p);
void			ft_result_letter_b_8(t_printf *link, long *p);
int				ft_result_letter_b_9(t_printf *link, long *p);
void			ft_result_letter_b_10(t_printf *link, long *p);
int				ft_result_letter_b_11(t_printf *link, long *p);
void			ft_result_letter_b_12(t_printf *link, long *p);
int				ft_result_letter_b_13(t_printf *link, long *p);
int				ft_result_letter_b_14(t_printf *link, long *p);
void			ft_result_letter_b_15(t_printf *link, long *p);

#endif
