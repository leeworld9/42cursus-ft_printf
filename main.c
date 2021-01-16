#include "ft_printf.h"

int main()
{
	int num1;
	void *ptr = &num1;

	// ft_printf("testsdtset\n");
	// ft_printf("test c1 : %c, test c2 : %caggg\n", 'v', 's');
	// ft_printf("string test1 : %s, string test2 : %s \n", "test1", "test2");

	// printf("|%c|\n", 'a');    // a: 문자
	// printf("|%s|\n", "Hello, world!");    // Hello, world!: 문자열
	// printf("|%p|\n", ptr);    // 008BFB6C: 포인터의 메모리 주소
	// printf("|%d|\n", -20);     // -20: 부호 있는 10진 정수
	// printf("|%i|\n", -20);     // -20: 부호 있는 10진 정수
	// printf("|%u|\n", 10);      //  10: 부호 없는 10진 정수
	// printf("|%x|\n", 0xF1);    //  f1: 부호 없는 16진 정수(소문자)
	// printf("|%X|\n", 0xF1);    //  F1: 부호 없는 16진 정수(대문자)
	// printf("|%%|\n");    // %: % 기호 출력
	
	//printf("-------------------------------------------------\n");
	// ft_printf("|%c|\n", 'a');    // a: 문자
	// ft_printf("|%s|\n", "Hello, world!");    // Hello, world!: 문자열
	// ft_printf("|%p|\n", ptr);    // 008BFB6C: 포인터의 메모리 주소
	//ft_printf("|%d|\n", -20);     // -20: 부호 있는 10진 정수
	//ft_printf("|%i|\n", -20);     // -20: 부호 있는 10진 정수
	// ft_printf("|%u|\n", 10);      //  10: 부호 없는 10진 정수
	// ft_printf("|%x|\n", 0xF1);    //  f1: 부호 없는 16진 정수(소문자)
	// ft_printf("|%X|\n", 0xF1);    //  F1: 부호 없는 16진 정수(대문자)
	// ft_printf("|%%|\n");
	
	// printf("-------------------------------------------------\n");
	printf("|%16d|\n", 20);         
	printf("|%-16d|\n", 20);   
	printf("|%0-166d|\n", 220);        
	printf("|%016d|\n", 2000);
	printf("|%5.7d|\n", 123);
	printf("|%.7d|\n", 123);
	printf("|%*d|\n", 7, 999);
	printf("|%7.5d|\n", 321);
	printf("|%07.5d|\n", 321);
	printf("|%-7.5d|\n", 321);
	printf("|%7.5d|\n", 0);
	printf("|%07.5d|\n", 0);
	printf("|%-7.5d|\n", 0);
	printf("|%7.1d|\n", 321);
	printf("|%07.1d|\n", 321);
	printf("|%-7.1d|\n", 321);
	printf("|%2.7d|\n", 321);
	printf("|%02.7d|\n", 321);
	printf("|%-2.7d|\n", 321);
	printf("|%5.0d|\n", 123);


	// printf("|%7.5d|\n", 654321);
	// printf("|%7.5d|\n", 7654321);
	// printf("|%5.7d|\n", 123);
	// printf("|%5.7d|\n", 123456);
	// printf("|%5.7d|\n", 1234567);
	// printf("|%.7d|\n", 123);
	// printf("|%*.*d|\n",10 , 7, 9898798);
	// printf("|%.7d|\n", 123456);
	// printf("|%.7d|\n", 1234567);
	// printf("|%.7d|\n", 123);
	// printf("|%.7d|\n", 123456);
	// printf("|%.7d|\n", 1234567);
	// printf("|%.7d|\n", 7777);
	// printf("|%5.7d|\n", 12311111);
	// printf("|%.7d|\n", 12311111);
	// printf("|%5.d|\n", 123);
	// printf("|%5.2d|\n", 123);
	// printf("|%5.0d|\n", 123);
	// printf("|%5.-2d|\n", 123);
	// printf("|%5.*d|\n", -2, 9);
	// printf("|%5.d|\n", 0);
	// printf("|%5.0d|\n", 0);
	// printf("|%.-2d|\n", 0);
	// printf("|%5.*d|\n", -2, 0);

	ft_printf("-------------------------------------------------\n");
	ft_printf("|%16d|\n", 20);          
	ft_printf("|%-16d|\n", 20);   
	ft_printf("|%0-166d|\n", 220);        
	ft_printf("|%016d|\n", 2000);
	ft_printf("|%5.7d|\n", 123);
	ft_printf("|%.7d|\n", 123);
	ft_printf("|%*d|\n", 7, 999);
	ft_printf("|%7.5d|\n", 321);
	ft_printf("|%07.5d|\n", 321);
	ft_printf("|%-7.5d|\n", 321);
	ft_printf("|%7.5d|\n", 0);
	ft_printf("|%07.5d|\n", 0);
	ft_printf("|%-7.5d|\n", 0);
	ft_printf("|%7.1d|\n", 321);
	ft_printf("|%07.1d|\n", 321);
	ft_printf("|%-7.1d|\n", 321);
	ft_printf("|%2.7d|\n", 321);
	ft_printf("|%02.7d|\n", 321);
	ft_printf("|%-2.7d|\n", 321);
	ft_printf("|%5.0d|\n", 123);
}