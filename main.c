#include "ft_printf.h"

int main()
{
	int num1;
	void *ptr = &num1;

	// ft_printf("testsdtset\n");
	// ft_printf("test c1 : %c, test c2 : %caggg\n", 'v', 's');
	// ft_printf("string test1 : %s, string test2 : %s \n", "test1", "test2");

	printf("|%c|\n", 'a');    // a: 문자
	printf("|%s|\n", "Hello, world!");    // Hello, world!: 문자열
	printf("|%p|\n", ptr);    // 008BFB6C: 포인터의 메모리 주소
	printf("|%d|\n", -20);     // -20: 부호 있는 10진 정수
	printf("|%i|\n", -20);     // -20: 부호 있는 10진 정수
	printf("|%u|\n", 10);      //  10: 부호 없는 10진 정수
	printf("|%x|\n", 0xF1);    //  f1: 부호 없는 16진 정수(소문자)
	printf("|%X|\n", 0xF1);    //  F1: 부호 없는 16진 정수(대문자)
	printf("|%%|\n");    // %: % 기호 출력
	
	printf("-------------------------------------------------\n");
	ft_printf("|%c|\n", 'a');    // a: 문자
	ft_printf("|%s|\n", "Hello, world!");    // Hello, world!: 문자열
	ft_printf("|%p|\n", ptr);    // 008BFB6C: 포인터의 메모리 주소
	ft_printf("|%d|\n", -20);     // -20: 부호 있는 10진 정수
	ft_printf("|%i|\n", -20);     // -20: 부호 있는 10진 정수
	ft_printf("|%u|\n", 10);      //  10: 부호 없는 10진 정수
	ft_printf("|%x|\n", 0xF1);    //  f1: 부호 없는 16진 정수(소문자)
	ft_printf("|%X|\n", 0xF1);    //  F1: 부호 없는 16진 정수(대문자)
	ft_printf("|%%|\n");
	
	// printf("-------------------------------------------------\n");
	// printf("|%6d|\n", 20);      
	// printf("|% d|\n", 20);      
	// printf("|%-06d|\n", 20);    // `0` 플래그는 `-` 와 사용될때 무시됨 (warning))
	// printf("|%-6d|\n", 20);        
	// printf("|%.2f|\n", 201.2412);   
	// printf("|%06d|\n", 2000);    
	// printf("-------------------------------------------------\n");
	// printf("|%5.d|\n", 123);
	// printf("|%5.0d|\n", 123);
	// printf("|%5.-2d|\n", 123);
	// printf("|%5.*d|\n", -2, 9);
	// printf("-------------------------------------------------\n");
	// printf("|%5.d|\n", 0);
	// printf("|%5.0d|\n", 0);
	// printf("|%5.-2d|\n", 0);
	// printf("|%5.*d|\n", -2, 0);
}