/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:42:03 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:42:08 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision(t_format *form, char **str, va_list *ap)
{
	form->precision = 1;
	*str = *str + 1;
	if (**str == '*')
	{
		form->p_val = va_arg(*ap, int);
		*str = *str + 1;
	}
	else
	{
		form->p_val = ft_atoi(*str);
		while (ft_isdigit(**str))
			*str = *str + 1;
	}
}
