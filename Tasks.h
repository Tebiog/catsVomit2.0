#include <iostream>
#include <vector>	// vector
#include <ctime>	//time
#include <SFML/Audio.hpp> // audio
#include <fstream>
#include <string>
enum class TaskType {
	command,
	sound,
	messageBox,
	None
};
class Task {
	time_t taskTime;
	std::string command;
	TaskType type;
public:
	//Constructors
	Task()
	{
		taskTime = time(NULL);
		command = "";
		type = TaskType::None;
	}
	Task(time_t _taskTime, std::string _command, TaskType _type)
	{
		taskTime = _taskTime;
		command = _command;
		type = _type;
	}
	//ex "2022.11.23 22:00"
	Task(std::string _taskTime, std::string _command, TaskType _type)
	{
		//converting from str to time_t
		time_t curr_time = time(NULL);
		tm* tm_gmt = gmtime(&curr_time);
		tm_gmt->tm_year += 1900;
		const char* T = _taskTime.c_str();
		time_t result = 0;
		int year = 0, month = 0, day = 0, hour = 0, min = 0;
		if (sscanf(T, "%4d.%2d.%2d %2d:%2d", &year, &month, &day, &hour, &min) == 5) {
			struct tm breakdown = { 0 };
			breakdown.tm_year = year - 1900;
			breakdown.tm_mon = month;
			breakdown.tm_mday = day;
			breakdown.tm_hour = hour + 2;
			breakdown.tm_min = min;
			if ((result = mktime(&breakdown)) == (time_t)-1) {
				fprintf(stderr, "Could not convert time input to time_t\n");
			}

			tm* tmp = gmtime(&result);
			std::cout << tmp->tm_min << std::endl;
			taskTime = result;
			command = _command;
			type = _type;
		}
		else {
			std::cout << "Incorrect data";
			taskTime = time(NULL);
			command = " ";
			type = TaskType::None;
		}
	}
	//Getters Setters
	TaskType GetType() {
		return type;
	}
	time_t GetTime() {
		return taskTime;
	}
	std::string GetCommand() {
		return command;
	}
};








class Tasks {
	std::vector<Task> tasks;
public:
	Task GetFirstTask() {
		return tasks[0];
	}
	void AddTask(Task _task) {
		tasks.push_back(_task);

	}
	void RemoveFirstTask() {
		tasks.erase(tasks.begin()); 
	}
	int getCoutOfTasks() {
		return tasks.size();
	}
	void PlayTask() {
		Task task = GetFirstTask();
		switch (task.GetType())
		{
		case TaskType::command:
			std::cout << "Command: " << task.GetCommand() << " is running" << std::endl;
			system(task.GetCommand().c_str());
			break;
		case TaskType::messageBox:
			std::cout << "message box is showing" << std::endl;
			break;
		case TaskType::sound:
			std::cout << "Soud is playing" << std::endl;
			//sf::SoundBuffer buffer;
			//if (!buffer.loadFromFile(task.GetCommand())) {
			//	break;
			//}
			//sf::Sound sound;
			//sound.setBuffer(buffer);
			//sound.play();

			break;
		}
		RemoveFirstTask();
	}
	void GetDataFromFolder() {
		std::string path = "../tasks";

	}
};
