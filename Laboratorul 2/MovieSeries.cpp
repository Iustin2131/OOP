#define _CRT_SECURE_NO_WARNINGS
#include "MovieSeries.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>

void MovieSeries::init()
{
	this->count = 0;
}

void MovieSeries::add(Movie* ep5)
{
	if (count <= 16)
		count++;
	 v[count] = ep5;
}

void MovieSeries::sort()
{
	for(int i=1;i<=count;i++)
		for(int j=i+1;j<=count;j++)
			if(v[i]->get_year()>v[j]->get_year())
            {
                int aux_year = v[i]->get_year();
                v[i]->set_year(v[j]->get_year());
                v[j]->set_year(aux_year);

                double aux_score = v[i]->get_score();
                v[i]->set_score(v[j]->get_score());
                v[j]->set_score(aux_score);

                int aux_len = v[i]->get_length();
                v[i]->set_length(v[j]->get_length());
                v[j]->set_length(aux_len);

                char aux_name[256];
                strcpy(aux_name, v[i]->get_name());
                v[i]->set_name(v[j]->get_name());
                v[j]->set_name(aux_name);
            }
}

void MovieSeries::print()
{
    for (int i = 1; i <= count; i++) {
        std::cout << "Movie name: " << v[i]->get_name() << " Score: " << v[i]->get_score()
            << " Year: " << v[i]->get_year() << " Length: " <<v[i]->get_length();
        std::cout << '\n';
    }
}



