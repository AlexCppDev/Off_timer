#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <string>
#include "time_proj.h"
#include "Calculate.h"
#include <Windows.h>
#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif



int main()
{
	int h, m, s;
	std::cout << "H";
	std::cin >> h;
	std::cout << "M";
	std::cin >> m;
	std::cout << "S";
	std::cin >> s;

	SortedTime time_t;
	time_t.setHours(h);
	time_t.setMinutes(m);
	time_t.setSeconds(s);
	//setlocale(LC_ALL, "Russian");
	Calculating obj; 
	std::cout << std::endl;
	std::cout << obj.get_needed_time(time_t) << std::endl;
	char* array_time = new char[10];
	_itoa (obj.get_needed_time(time_t), array_time,10);
	std::string str_time = std::string(array_time);
	
	std::string shutdown_str = "shutdown -s -t " + str_time;
	
	char *char_shutdown = &shutdown_str[0];
	std::cout << char_shutdown; 

	WinExec(char_shutdown,SW_HIDE);


	
	return 0;
	_CrtDumpMemoryLeaks();
}

