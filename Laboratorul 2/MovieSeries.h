#pragma once
#include<iostream>
#include<string>
#include "Movie.cpp"

class MovieSeries
{
	Movie *v[16];
	int count;
public:
   void	init();
   void add(Movie* ep5);
   void sort();
   void print();
};

