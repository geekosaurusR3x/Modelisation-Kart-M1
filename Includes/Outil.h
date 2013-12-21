#include <sstream>
#include <string>


int StrToInt(std::string s)
{
	int entier;
	std::istringstream iss(s);
	iss >>  entier;
	return entier;
}


double StrToFloat(std::string s)
{
	double d;
	std::istringstream iss(s);
	iss >>  d;
	return d;
}