#pragma once
class Movie
{
	char name[256];
	double score;
	int year;
	int length;

public:
	void set_name(const char* name);
	void set_score(double score);
	void set_year(int year);
	void set_length(int length);
	double get_score();
	const char* get_name();
	int get_year();
	int get_length();
	int get_passed_years();
};

