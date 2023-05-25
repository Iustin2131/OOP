#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include "comper.h"
#include<string>


void Movie::set_name(const char* name)
{
	strcpy(this->name,name);
}

void Movie::set_score(double score)
{
	this->score = score;
}

void Movie::set_year(int year)
{
	this->year = year;
}

void Movie::set_length(int length)
{
	this->length = length;
}

double Movie::get_score()
{
	return this->score;
}

const char* Movie::get_name()
{
	return this->name;
}

int Movie::get_year()
{
	return this->year;
}

int Movie::get_passed_years()
{
	return 2023-this->year;
}

int Movie::get_length()
{
	return this->length;
}