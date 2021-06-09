#ifndef TIME_PROJ_H
#define TIME_PROJ_H
#include <QTime>

class SortedTime
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    void setHours(int h);
    int getHours();
    void setMinutes(int t);
    int getMinutes();
    void setSeconds(int t);
    int getSeconds();
};

#endif // TIME_PROJ_H
