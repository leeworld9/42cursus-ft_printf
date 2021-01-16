/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:36 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/16 17:37:05 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char get_flag(t_printf data)
{
	char *tmp;

	while ((tmp = ft_strchr(FT_FLAG, *data.tag)) != NULL)
	{
		// `0` 플래그는 `-` 와 사용될때 무시됨 (warning))
		if ((data.flag) == '-')
			break;
		data.flag = *tmp;
		data.tag++;
	}
	return (data.flag);
}

static int get_presision(va_list ap, t_printf data)
{
	char *tmp;

	if (tmp = ft_strchr(data.tag, '.'))
	{
		if (ft_strchr(data.tag, '*'))
		{
			if ((data.presision = va_arg(ap, int)) < 0)
				; //fill_space((int)ft_strlen(data.tag) + 2); // 여긴 수정될 수 있음
		}
		else
			data.presision = ft_atoi(++tmp);
	}
	else
		return (0);
	return (data.presision);
}

static int get_width(va_list ap, t_printf data)
{
	char *tmp;
	
	if (ft_strchr(data.tag, '.') == NULL)
	{
		if (ft_strchr(data.tag, '*'))
			data.width = abs_convert(va_arg(ap, int));
		else
		{
			while (ft_strchr(FT_FLAG, *data.tag))
			data.tag++;
			data.width = ft_atoi(data.tag);
		}	
	}
	else
	{	
		tmp = ft_substr(data.tag, 0, find_chr_idx(data.tag, '.'));
		while (ft_strchr(FT_FLAG, *data.tag))
			data.tag++;
		data.width = ft_atoi(data.tag);	
		free(tmp);
	}
	return (data.width);
}

static void ft_dislpay(t_printf data, char *param)
{
	char *result;
	int max;

	if (data.presision >= data.width)
		max = ((data.presision > data.len) ? data.presision : data.len);
	else
		max = ((data.width > data.len) ?  data.width : data.len);

	result = (char *)malloc(sizeof(char) * (max + 1));
	result[max] = '\0';

	//printf("width : %i, presision :%i \n", data.width, data.presision);

	if (data.presision == 0 && data.flag == '0')
		fill_chr(max, data.width, result, '0');
	else
		fill_chr(max, data.width, result, ' ');
	fill_chr(max, data.presision, result, '0');
	if (data.flag == '-')
	{
		fill_result(max, data.len, result, param);
		left_sort(result, max);
	}
	else
		fill_result(max, data.len, result, param);
	ft_putstr_fd(result, 1);
	
	free(result);
}

void ft_printf_di(va_list ap, char *target, int i)
{
	t_printf data;
	char *param;
	int j;

	j = 0;
	data.flag = '\0';
	data.tag = ft_substr(target, 1, i - 1);

	data.flag = get_flag(data);
	data.presision = get_presision(ap, data);
	data.width = get_width(ap, data);

	param = ft_itoa(va_arg(ap, int));
	data.len = ft_strlen(param);

	ft_dislpay(data, param);
	
	// ft_putstr_fd("flag : ", 1);
	// ft_putchar_fd(data.flag, 1);
	// ft_putstr_fd("\n", 1);
	// ft_putstr_fd("presision : ", 1);
	// ft_putstr_fd(ft_itoa(data.presision), 1);
	// ft_putstr_fd("\n", 1);
	// ft_putstr_fd("width : ", 1);
	// ft_putstr_fd(ft_itoa(data.width), 1);
	// ft_putstr_fd("\n", 1);

	free(param);
	free(data.tag);
}