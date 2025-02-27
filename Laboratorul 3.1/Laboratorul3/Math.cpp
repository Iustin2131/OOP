#define _CRT_SECURE_NO_WARNINGS
#include <cstdarg>
#include <cstring>
#include "Math.h"


int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}

double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

double Math::Mul(double a, double b)
{
	return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		int arg = va_arg(args, int);
		sum += arg;
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
	{
		return nullptr;
	}
	char* result = new char[strlen(str1) + strlen(str2) + 1];
	strcpy(result, str1);
	strcat(result, str2);
	return result;
}