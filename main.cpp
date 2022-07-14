#include <iostream>
#include <ctime>
#include<dos.h>
#include "Tasks.h"
#include <windows.h>

int main()
{
	Tasks tasks;
	time_t curr_time = time(NULL);
	tm* tm_gmt = gmtime(&curr_time);


	Task task("2022.06.12 13:31", "calc", TaskType::command);
	tasks.AddTask(task);
	time_t tmp = tasks.GetFirstTask().GetTime();
	tm* tpmtm = gmtime(&tmp);
	std::cout << tpmtm->tm_min << std::endl;

	tasks.GetDataFromFolder();

	//	tasks.PlayTask();
	while (true)
	{
		curr_time = time(NULL);
		tm_gmt = gmtime(&curr_time);
		std::cout << tm_gmt->tm_min << "\n";
		if (tasks.getCoutOfTasks() >= 1) {
			if (tasks.GetFirstTask().GetTime() <= curr_time) {
				tasks.PlayTask();
			}
			Sleep(60000 - (tm_gmt->tm_sec * 1000));
		}
		else {
			break;
		}
	}
	return 0;
}
/*
	ПРОБЛЕМЫ:


*/