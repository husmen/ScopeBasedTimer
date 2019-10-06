#include "ScopeBasedTimer.hpp"
#include <iostream>

int main()
{
	//vector <Timer::timer_struct> log_vec;
	

	int value = 0;
	{
		Timer timer;
		cout << "Hello world\n";
		for (int i = 0; i < 1000000; i++)
			value += 1;
	}
	{
		Timer timer;
		cout << "Hello world, Again\n";
		for (int i = 0; i < 1000000; i++)
			value += 1;
	}

	TimerLog& logger = TimerLog::getInstance();
	vector <timer_struct> *log_vec = &logger.GetData();
	for (auto it = (*log_vec).begin(); it != (*log_vec).end(); ++it)
		cout << (*it).id << " | " << (*it).duration_us << endl;

	{
		Timer timer;
		cout << "Hello world, One last time\n";
		for (int i = 0; i < 1000000; i++)
			value += 1;
	}

	for (auto it = (*log_vec).begin(); it != (*log_vec).end(); ++it)
		cout << (*it).id << " | " << (*it).duration_us << endl;
	//__debugbreak();
	cin.get();
	return 0;
}