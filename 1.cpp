#include<iostream>
#include<cstdio>
int main()
{
	printf("*************************************************************************\r\n");
	printf("*			Nizhniy Novgorod Technical University		*\r\n");
	printf("*			Study work number 1. Task number 1.		*\r\n");
	printf("*	Performed student grupp 20-IVT-2. Zhalnina Ekaterina Evgenevna	*\r\n");
	printf("*************************************************************************\r\n");
	printf("enter an integer in the decimal system\r\n");//¬ывод на экран текста вопроса
	int Number;//создание переменной
	std::cin >> Number;//»нециализаци€ переменной
	printf("10: % i\n8 : % o\n16 : % X\n", Number, Number, Number);//вывод переменой в разных системах счислени€
	return 0;
}
