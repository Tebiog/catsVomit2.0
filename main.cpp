#include <iostream>
#include <ctime>
#include<dos.h>
#include "Tasks.h"
#include <windows.h>

int main()
{
	Tasks tasks;
	tasks.GetDataFromFolder();
	time_t curr_time = time(NULL);
	tm* tm_gmt = gmtime(&curr_time);
	time_t tmp;

	Task task("2022.07.16 14:57", "0", TaskType::sound);
	tasks.AddTask(task);

	tasks.SortTasks();
	tm* tpmtm;

	while (true)
	{

		tmp = tasks.GetFirstTask().GetTime();
		curr_time = time(NULL);
		tm_gmt = gmtime(&curr_time);
		std::cout << "Current: " << tm_gmt->tm_mday << tm_gmt->tm_hour << tm_gmt->tm_min << std::endl;
		std::cout << "Tasks left: " << tasks.getCoutOfTasks() << std::endl;
		if (tasks.getCoutOfTasks() >= 1) {
			std::cout << tasks.GetFirstTask().GetTime() << " curr: " << curr_time << std::endl;
			if (curr_time >= tasks.GetFirstTask().GetTime()) {
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
