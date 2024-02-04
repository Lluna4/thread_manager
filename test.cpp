#include "thread_manager.hpp"

void test_func(std::stop_token stoken,std::string str, int nbr)
{
	std::cout << "Thread started!\n";
	while (1)
	{
		if (stoken.stop_requested())
		{
			std::cout << "Requested stop!\n";
			return;
		}
	}
}

int main()
{
	thread_man a;
	std::function<void(std::stop_token, std::string, int)> func = test_func;
	a.add_thread(func, "aaaa", 1212);
	a.stop_all_threads();
	return 0;
}
