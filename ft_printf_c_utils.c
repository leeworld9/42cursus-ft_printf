/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:31:44 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 14:52:41 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_c_maxlen(t_printf *data, int param_len)
{
	if (param_len == 0)
		param_len = 1;
	if (data->width == 0)
		data->max_len = param_len;
	else if (data->width > 0)
		data->max_len = data->width;
}

void	ft_c_putstr_fd(t_printf *data, char *result, int fd)
{
	int i;
	int len;

	i = 0;
	len = data->max_len;
	if ((char)data->i_param == '\0')
	{
		while (len > 0)
		{
			write(fd, &result[i], 1);
			i++;
			len--;
		}
	}
	else
		ft_putstr_fd(result, fd);
}
