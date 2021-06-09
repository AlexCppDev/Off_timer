#include "calcutate.h"
#include "time_proj.h"

int Calculating::get_needed_time(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
    //return h*3600 + m*60 + s;
    //return  t.getHours() + t.getMinutes() + t.getSeconds();
};
