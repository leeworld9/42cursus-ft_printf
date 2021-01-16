/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:50:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/16 14:45:55 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
https://dojang.io/mod/page/view.php?id=736

서식 지정자: cspdiuxX%          // 보너스 : nfge (4개중 한개 이상 구현)
c : 문자
s : 문자열
p : 포인터의 메모리 주소
d : 부호 있는 10진 정수
i : 부호 있는 10진 정수 (d와 동일)
u : 부호 없는 10진 정수
x : 부호 없는 16진 정수(소문자)
X : 부호 없는 16진 정수(대문자)
% : %의 이스케이프 문자
===========================================
플래그 -0.*                    // 보너스1 : # +(가운데는 공백, 모두 구현), 보너스2 : l ll h hh (4개중 한개 이상 구현)
- : 왼쪽정렬
0 : 출력하는 폭의 남는 공간에 0으로 채움
.숫자 :.n (n은 10진수) 실수일 때 소수점 이하의 자릿 수를 결정한다. 
			일부 specifier에서만 사용 가능하고 그 외의 값에서는 무시한다. (실수형, 문자열, 정수형에서 사용 가능)
* : 서식문자로 출력할 인수 앞에 가변인수로 필드의 폭(width)을 결정한다.

과카몰리에서 비교
printf 결과 비교
*/

static int	find_printstr_idx(char *target)
{
	int i;

	i = 0;
	while (target[i] != '\0')
	{
		if (ft_strchr("%", target[i]))
			break ;
		i++;
	}
	return (i);
}

static int	find_specifier(char *target)
{
	int i;

	i = 1;/* `%` 제외하고 찾기 */
	while (target[i] != '\0')
	{
		if (ft_strchr(FT_SEPECIFIER, target[i]))
			break ;
		i++;
	}
	if ((int)ft_strlen(target ) == i)
		return (-1);
	return (i);
}

static void print_format(char *target, va_list ap, int i)
{
	if (target[i] == 'c')
		ft_printf_c(ap, target, i);
	else if (target[i] == 's')
		ft_printf_s(ap, target, i);
	else if (target[i] == 'p')
		ft_printf_p(ap, target, i);
	else if (target[i] == 'd' || target[i] == 'i')
		ft_printf_di(ap, target, i);
	else if (target[i] == 'u' ||target[i] == 'x' || target[i] == 'X')
		ft_printf_uxX(ap, target, i);
	else if (target[i] == '%' && i == 1)
		ft_putstr_fd("%", 1);
}

/* 기본서식 : %[플래그][폭][.정밀도,길이]서식지정자 */
//            %[flag][width][.precision]서식지정자
// 마지막에 main.c 지우기!!
int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*target;
	char	*tmp;

	i = 0;
	va_start(ap, format);
	while (true)
	{	
		if ((target = ft_strchr((char *)format, '%')) != NULL) // target은 `%`로 시작하는 문자열
		{
			if ((i = find_specifier(target)) > 0) // i는 서식지정자 idx
			{
				tmp = ft_substr(format, 0, find_printstr_idx((char *)format));
				ft_putstr_fd(tmp, 1);  // 서식지정자 전 까지 출력
				free(tmp);
				print_format(target, ap, i);
				format = target + i + 1;
			}
		}
		else
		{
			ft_putstr_fd((char *)format, 1);
			break ;
		}
	}
	va_end(ap);
	return (0);
}
