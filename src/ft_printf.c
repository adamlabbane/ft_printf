/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 08:56:38 by adlabban          #+#    #+#             */
/*   Updated: 2018/11/04 18:56:12 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_ft_end(t_flag *f)
{
	if (f->fla[0] >= 0 && f->arg != NULL && f->arg[0] != '\0' &&
			f->arg[0] != '0')
	{
		if (f->spe == 'x' || f->spe == 'X' || f->spe == 'o' || f->spe == 'O'
			|| f->spe == 'u' || f->spe == 'U' || f->spe == 'd' || f->spe == 'D'
			|| f->spe == 'p' || f->spe == 'S' || f->spe == 'i' || (f->spe == 's'
					&& f->fla[0] < pf_ft_strlen(f->arg) && f->fla[0] > 0) ||
				f->spe == 'C' || (f->spe == 'c' && f->fla[10] == 1))
			free(f->arg);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flag		f;
	int			i;

	va_start(ap, format);
	i = -1;
	f.ret = 0;
	pf_ft_bufset();
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f.frmt = (char*)&format[++i];
			if (pf_ft_dispatcher(&f, &ap) == -1)
				break ;
			i += f.ndx;
		}
		else if (format[i] != '\0' && format[i] != '%')
			pf_ft_buf(format[i], &f);
	}
	if (g_i > 0)
		pf_ft_display(&f);
	va_end(ap);
	return (f.ret);
}
