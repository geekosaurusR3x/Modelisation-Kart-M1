#pragma once

#include <exception>

class ExceptionRegain: public std::exception
{
public :
	ExceptionRegain (char *ch)
		: exception (ch)
	{
	}
} ;