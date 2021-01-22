/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:31 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 13:34:56 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show_result(t_printf *data)
{
	int		param_len;
	char	*result;

	param_len = ft_strlen(data->strparam);
	get_s_maxlen(data, param_len);
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	// printf("w_after : %d, ", data->width);
	// printf("p_after : %d, ", data->pres);
	// printf("maxlen : %d, ", data->max_len);
	// printf("parlen : %d", param_len);
	if (data->flag == '0' && data->pres == 0)
		fill_chr(data, data->width, result, '0');
	else
		fill_chr(data, data->max_len, result, ' ');
	result = s_exception(data, result); 
	//printf("\nflag : %c, param : %s, width : %d, pres : %d, max_len : %d, param_len : %d\n", data->flag, data->strparam, data->width, data->pres, data->max_len, param_len);
	ft_putstr_fd(result, 1);
	free(result);
	return (data->max_len);
}

int ft_printf_s(va_list ap, char *target, int i)
{
	t_printf	*data;
	int len;

	len = 0;
	if ((data = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		return (0);
	data->tag = ft_substr(target, 1, i);
	data->flag = '\0';
	data->width = 0;
	data->pres = -1;
	data->minus = 0;

	get_flag(data);
	get_width(ap, data);
	get_pres(ap, data);

	data->strparam = va_arg(ap, char *);

	if (data->strparam != NULL)
	{
		len += show_result(data);
		// ft_putstr_fd(data->strparam, 1);
		// len += ft_strlen(data->strparam);
	}
	else
		ft_putstr_fd("(null)", 1);
	free(data->tag);
	free(data);
	return (len);
}