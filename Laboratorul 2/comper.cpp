#include "comper.h"

int movie_compare_name(Movie ep4, Movie ep5)
{
    return strcmp(ep4.get_name(), ep5.get_name());

}

int movie_compare_year(Movie ep4, Movie ep5)
{
	if (ep4.get_year() == ep5.get_year())
		return 0;
	else
		if (ep4.get_year() < ep5.get_year())
			return -1;
		else
			return 1;

}
int movie_compare_score(Movie ep4, Movie ep5)
{
	if (ep4.get_score() == ep5.get_score())
		return 0;
	else
		if (ep4.get_score() < ep5.get_score())
			return -1;
		else
			return 1;
}
int movie_compare_length(Movie ep4, Movie ep5)
{
	if (ep4.get_length() == ep5.get_length())
		return 0;
	else
		if (ep4.get_length() < ep5.get_length())
			return -1;
		else
			return 1;
}
int  movie_compare_years(Movie ep4, Movie ep5)
{
	if (ep4.get_passed_years() == ep5.get_passed_years())
		return 0;
	else
		if (ep4.get_passed_years() < ep5.get_passed_years())
			return -1;
		else
			return 1;
}