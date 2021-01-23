/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:46:56 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 15:29:07 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_hex(unsigned int num, char spec, char *param)
{
	int j;

	j = 0;
	while (true)
	{
		if (num / 16 != 0)
		{
			if (spec == 'X')
				param[j] = ft_toupper("0123456789abcdef"[num % 16]);
			else
				param[j] = "0123456789abcdef"[num % 16];
			num = num / 16;
		}
		else
		{
			if (spec == 'X')
				param[j] = ft_toupper("0123456789abcdef"[num]);
			else
				param[j] = "0123456789abcdef"[num];
			param[j + 1] = '\0';
			break ;
		}
		j++;
	}
}

static int	get_hex(t_printf *data, char spec)
{
	char *param;
	char *result;

	if ((param = (char *)malloc(sizeof(char) * (64 / 4 + 1))) == NULL)
		return (0);
	convert_hex((unsigned int)data->param, spec, param);
	reverse_arr(param);
	get_ux_maxlen(data, ft_strlen(param));
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	fill_chr(data, data->max_len, result, ' ');
	result = ux_exception(data, result, param);
	ft_putstr_fd(result, 1);
	free(param);
	free(result);
	return (data->max_len);
}

static int	show_result(t_printf *data, char *param, char spec)
{
	int		param_len;
	char	*result;

	if (spec == 'u')
	{
		param_len = ft_strlen(param);
		get_ux_maxlen(data, param_len);
		if ((result = malloc(sizeof(char) * (data->max_len + 1))) == NULL)
			return (0);
		result[data->max_len] = '\0';
		result = ux_exception(data, result, param);
		ft_putstr_fd(result, 1);
		free(result);
	}
	else if (spec == 'x' || spec == 'X')
	{
		if ((data->max_len = get_hex(data, spec)) == 0)
			return (0);
	}
	return (data->max_len);
}

static int	select_spec(va_list ap, t_printf *data, char *target, int i)
{
	char		*param;
	long long	num;
	int			len;

	len = 0;
	if (target[i] == 'u')
	{
		num = va_arg(ap, long long);
		while (num < 0 || num > UINT_MAX)
		{
			if (num > UINT_MAX)
				num = num - UINT_MAX - 1;
			else if (num < 0)
				num = UINT_MAX + num + 1;
		}
		param = ft_ltoa(num);
		len += show_result(data, param, target[i]);
		free(param);
	}
	else if (target[i] == 'x' || target[i] == 'X')
	{
		data->param = va_arg(ap, unsigned int);
		len += show_result(data, NULL, target[i]);
	}
	return (len);
}

int			ft_printf_ux(va_list ap, char *target, int i)
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
	len += select_spec(ap, data, target, i);
	free(data->tag);
	free(data);
	return (len);
}
