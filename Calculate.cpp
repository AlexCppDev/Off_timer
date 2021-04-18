#pragma once
#include "Calculate.h"


int Calculating::get_needed_time(SortedTime t)
{
	return  t.getHours() + t.getMinutes() + t.getSeconds();
};