/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 19:55:43 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 14:25:07 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct	s_parameters
{
	uint8_t		negative:1;
	uint8_t		zero:1;
	uint8_t		point:1;
	uint8_t		plus:1;
	uint8_t		hash:1;
	uint8_t		error:1;
	uint8_t		is_int:1;
	uint8_t		is_str:1;
	int			is_char;
	uint8_t		sp:1;
	int			ret;
	size_t		alloc;
	int			pos;
	int			prec;
	long int	field;
	char		*str;
	va_list		list_arg;
}				t_params;

int				ft_printf(const char *format, ...);
t_params		ft_asprintf(char *format, t_params par);
t_params		ft_printf_write(char *format, t_params par);
t_params		ft_printf_rules(char *format, t_params par);
t_params		ft_printf_field(char *format, t_params par);
t_params		ft_printf_prec(char *format, t_params par);
t_params		ft_printf_flags(char *format, t_params par);
t_params		ft_printf_conv(char *format, t_params par);
t_params		ft_printf_conv_bonus(char *format, t_params par);
t_params		ft_printf_padding(t_params par);
t_params		ft_printf_negative(t_params par, int i);
t_params		ft_printf_zero(t_params par, int i);
t_params		ft_printf_star(t_params par, char *format);
t_params		ft_printf_hash(t_params par, char c);
t_params		ft_printf_space(t_params par, int i);
t_params		ft_printf_c(t_params par);
t_params		ft_printf_s(t_params par);
t_params		ft_printf_di(t_params par);
t_params		ft_printf_ldi(t_params par);
t_params		ft_printf_lu(t_params par);
t_params		ft_printf_hu(t_params par);
t_params		ft_printf_lx(t_params par, char *format);
t_params		ft_printf_hdi(t_params par);
t_params		ft_printf_hx(t_params par, char *format);
t_params		ft_printf_u(t_params par);
t_params		ft_printf_x(t_params par, char *format);
t_params		ft_printf_p(t_params par);
t_params		ft_printf_n(t_params par);
t_params		ft_printf_point(t_params par);
int				ft_free(char *str);

#endif
