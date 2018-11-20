/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:34:44 by adlabban          #+#    #+#             */
/*   Updated: 2018/11/04 17:34:47 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		pf_ft_wbytelen(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = pf_ft_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += pf_ft_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}

size_t		pf_ft_wstrlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (*(ws++))
		len++;
	return (len);
}
