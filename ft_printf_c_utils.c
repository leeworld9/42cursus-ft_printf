/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:31:44 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 10:29:27 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_c_maxlen(t_printf *data, int param_len)
{
	if (data->width == 0)
		data->max_len = param_len;
	else if (data->width > 0)
		data->max_len = data->width;
}