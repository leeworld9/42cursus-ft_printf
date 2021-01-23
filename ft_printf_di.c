/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:36 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 13:08:49 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show_result(t_printf *data)
{
	char	*param_abs;
	int		param_len;
	char	*result;

	param_abs = ft_ltoa(abs_convert(data->param));
	param_len = ft_strlen(param_abs);
	get_di_maxlen(data, param_len);
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	if (data->flag == '0' && data->pres == 0)
		fill_chr(data, data->width, result, '0');
	else
	{
		fill_chr(data, data->width, result, ' ');
		fill_chr(data, data->pres, result, '0');
	}
	result = di_exception(data, result, param_abs);
	ft_putstr_fd(result, 1);
	free(param_abs);
	free(result);
	return (data->max_len);
}

int			ft_printf_di(va_list ap, char *target, int i)
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
	data->param = va_arg(ap, int);
	data->minus = (data->param < 0) ? 1 : 0;
	len += show_result(data);
	free(data->tag);
	free(data);
	return (len);
}
