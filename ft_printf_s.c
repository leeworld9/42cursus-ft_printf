/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:31 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 15:28:47 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show_result(t_printf *data)
{
	int		param_len;
	char	*result;

	if (data->str_param == NULL)
		data->str_param = "(null)";
	param_len = ft_strlen(data->str_param);
	get_s_maxlen(data, param_len);
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	result = s_exception(data, result);
	ft_putstr_fd(result, 1);
	free(result);
	return (data->max_len);
}

int			ft_printf_s(va_list ap, char *target, int i)
{
	t_printf	*data;
	int			len;

	len = 0;
	if ((data = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		return (0);
	data->tag = ft_substr(target, 1, i);
	data->flag = '\0';
	data->width = 0;
	data->pres = -1;
	get_flag(data);
	get_width(ap, data);
	get_pres(ap, data);
	data->str_param = va_arg(ap, char *);
	len += show_result(data);
	free(data->tag);
	free(data);
	return (len);
}
