/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:43:45 by adlabban          #+#    #+#             */
/*   Updated: 2018/11/04 18:44:19 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_ft_apply_mask(t_flag *f, int *mask)
{
	int		i;

	i = 2;
	while (i < 14)
	{
		f->fla[i] = f->fla[i] * mask[i];
		i++;
	}
}

int			pf_ft_handler_char(t_flag *f)
{
	if (f->fla[0] != 0 && (f->spe != 'C' || (f->spe == 'c' && f->fla[10] == 1)))
		pf_ft_precision_string(f);
	else if (f->spe == 'S' || (f->spe == 's' && f->fla[10] == 1) ||
			f->spe == 'C' || (f->spe == 'c' && f->fla[10] == 1))
		f->arg = pf_ft_transform_wchar_in_char(f->warg);
	if (f->fla[1] > 0)
		pf_ft_width_char(f);
	if (f->fla[1] == 0)
		pf_ft_display_arg(f);
	return (1);
}

int			pf_ft_handler_numb(t_flag *f)
{
	int		i;

	i = -1;
	if (f->fla[0] == -1 && f->arg[0] == '0' && !(f->fla[2] == 1 &&
				(f->spe == 'o' || f->spe == 'O' || f->spe == 'p')))
		f->arg = "\0";
	if (f->fla[1] > 0)
		pf_ft_width_numb(f);
	else if (f->fla[1] == 0 && f->fla[0] > 0)
		pf_ft_precision_without_width(f);
	if (f->fla[0] <= 0 && f->fla[1] == 0)
		pf_ft_space_plus_sharp(f);
	while (f->arg[++i] != '\0' && f->fla[1] == 0)
		pf_ft_buf(f->arg[i], f);
	pf_ft_end(f);
	return (1);
}
