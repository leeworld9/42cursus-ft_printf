/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:31 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 09:07:10 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flag(t_printf *data)
{
	char	*tmp;
	int		pres_idx;
	int		i;

	i = 0;
	pres_idx = find_chr_idx(data->tag, '.');
	tmp = (pres_idx != -1) ? ft_substr(data->tag, 0, pres_idx) : data->tag;
	while (tmp[i] != '\0')
	{
		if (ft_strchr(FT_FLAG, tmp[i]) != NULL)
		{
			if ((data->flag) == '-')
				break ;
			data->flag = tmp[i];
		}
		i++;
	}
	if (pres_idx != -1)
		free(tmp);
}

static void	get_width(va_list ap, t_printf *data)
{
	int		pres_idx;
	char	*tmp;

	if ((pres_idx = find_chr_idx(data->tag, '.')) != -1)
	{
		tmp = ft_substr(data->tag, 0, pres_idx);
		if (ft_strchr(tmp, '*'))
			data->width = zero_flagchk(ap, data);
		else
			data->width = ft_atoi(flag_bypass(tmp));
		free(tmp);
	}
	else
	{
		if (ft_strchr(data->tag, '*'))
			data->width = zero_flagchk(ap, data);
		else
			data->width = ft_atoi(flag_bypass(data->tag));
	}
}

static void	get_pres(va_list ap, t_printf *data)
{
	char	*tmp;
	int		pres_idx;
	int		pres_size;
	int		i;

	i = 0;
	pres_idx = find_chr_idx(data->tag, '.');
	if (pres_idx != -1 && !ft_strchr(FT_SEPECIFIER, data->tag[pres_idx + 1]))
	{
		pres_size = ft_strlen(data->tag) - pres_idx - 1;
		tmp = ft_substr(data->tag, pres_idx + 1, pres_size);
		if (tmp[i] != '\0' && ft_strchr(tmp, '*'))
		{
			if ((data->pres = va_arg(ap, int)) == 0)
				data->pres = -1;
			else if (data->pres < 0)
				data->pres = 0;
		}
		else
		{
			if ((data->pres = ft_atoi(flag_bypass(tmp))) <= 0)
				data->pres = -1;
		}
		free(tmp);
	}
	else
		data->pres = (pres_idx != -1) ? -1 : 0;
}

static int	show_result(t_printf *data)
{
	int		param_len;
	char	*result;

	param_len = ft_strlen(data->strparam);
	get_s_maxlen(data, param_len);
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	if (data->flag == '0' && data->pres == 0)
		fill_chr(data, data->width, result, '0');
	else
		fill_chr(data, data->max_len, result, ' ');
	result = s_exception(data, result); 
	//printf("\nflag : %c, param : %s, width : %d, pres : %d, max_len : %d, param_len : %d\n", data->flag, data->strparam, data->width, data->pres, data->max_len, param_len);
	//printf("\nmax_len : %d\n",data->max_len);
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