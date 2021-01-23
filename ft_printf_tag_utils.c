/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tag_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:55:20 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 12:58:41 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(t_printf *data)
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

void	get_width(va_list ap, t_printf *data)
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

void	get_pres(va_list ap, t_printf *data)
{
	char	*tmp;
	int		pres_idx;
	int		pres_size;
	int		i;

	i = 0;
	pres_idx = find_chr_idx(data->tag, '.');
	if (pres_idx != -1 && !ft_strchr(FT_SEPECIFIER, data->tag[pres_idx + 1]))
	{
		pres_size = ft_strlen(data->tag) - pres_idx - 2;
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

char	*flag_bypass(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(FT_FLAG, *(str + i)))
		i++;
	return (str + i);
}

int		zero_flagchk(va_list ap, t_printf *data)
{
	int	argument;

	if ((argument = va_arg(ap, int)) < 0)
		data->flag = '-';
	return ((int)abs_convert(argument));
}
