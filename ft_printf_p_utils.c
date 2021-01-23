/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:45:10 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 14:51:00 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_p_maxlen(t_printf *data, int param_len)
{
	if (data->pres >= data->width)
		data->max_len = ((data->pres > param_len) ? data->pres : param_len);
	else
		data->max_len = ((data->width > param_len) ? data->width : param_len);
}
