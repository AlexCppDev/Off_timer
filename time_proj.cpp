#pragma once
#include "time_proj.h"

		void SortedTime::setHours(int h)
		{
			hours = h*3600;
		}
		int SortedTime::getHours()
		{
			return hours;
		}
		void SortedTime::setMinutes(int m)
		{
			minutes = m * 60;
		}
		int SortedTime::getMinutes()
		{
			return minutes;
		}
		void SortedTime::setSeconds(int t)
		{
			seconds = t;
		}
		int SortedTime::getSeconds()
		{
			return seconds;
		}

