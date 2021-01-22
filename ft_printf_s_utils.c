/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:01:07 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 14:31:32 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_s_maxlen(t_printf *data, int param_len)
{
	if (data->pres == 0)
	{
		if (data->width >= param_len)
			data->max_len = data->width;
		else
			data->max_len = param_len;
	}
	else
	{
		// w 4 p 7 max?  len = 1  -> width
		// w 0 p 2 max?  len = 1  -> param+len
		// w 3 p 2 len 16  -> w    
		// w 3 p 2 len 1  -> w
		if (param_len < data->width && param_len < data->pres)
			data->max_len = data->width;
		else if (data->width >= data->pres)
			data->max_len = data->width;
		else if (param_len < data->pres)
			data->max_len = param_len;
		else
			data->max_len = data->pres;
	}
}
void	fill_s_result(t_printf *data, char *result, char *param)
{
	int len;
	int param_len;
	int prs_tmp;

	prs_tmp = data->pres - 1;	
	len = data->max_len - 1;
	param_len = (int)ft_strlen(param);
	//printf("param_len : %d\n", param_len);
	if (param_len >= data->pres)
	{
		while (data->pres != -1)
		{
			result[len] = param[prs_tmp];
			len--;
			prs_tmp--;
			if (prs_tmp == -1)
				break ;
		}
	}
	else
	{
		while (len != -1)
		{
			result[len] = param[param_len - 1];
			len--;
			param_len--;
			if (param_len == 0)
				break;
		}
	}
	

}