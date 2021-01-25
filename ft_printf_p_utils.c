/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:45:10 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 14:45:22 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_p_maxlen(t_printf *data, int param_len)
{
	if (data->prec >= data->width)
		data->max_len = ((data->prec > param_len) ? data->prec : param_len);
	else
		data->max_len = ((data->width > param_len) ? data->width : param_len);
}
