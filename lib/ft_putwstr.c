/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:32:50 by adlabban          #+#    #+#             */
/*   Updated: 2018/11/04 17:32:54 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_ft_putwstr(wchar_t *ws)
{
	size_t	len;

	len = pf_ft_wstrlen(ws);
	while (len > 0)
	{
		pf_ft_putwchar(*ws, f);
		ws++;
		len--;
	}
}
