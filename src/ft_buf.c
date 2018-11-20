/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affsturc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:15:19 by adlabban          #+#    #+#             */
/*   Updated: 2018/11/04 18:55:27 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_ft_bufset(void)
{
	int		n;

	n = 0;
	while (n < 4096)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_i = 0;
}

void		pf_ft_display(t_flag *f)
{
	f->ret += write(1, g_buf, g_i);
	pf_ft_bufset();
}

void		pf_ft_buf_null(t_flag *f)
{
	static char str[6] = "(null)";
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		pf_ft_buf(str[i], f);
		i++;
	}
}

void		pf_ft_buf(char c, t_flag *f)
{
	g_buf[g_i] = c;
	g_i++;
	if (g_i == 4096)
		pf_ft_display(f);
}
