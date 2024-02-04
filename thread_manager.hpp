# include <thread>
# include <iostream>
# include <vector>
# include <functional>

class thread_man
{
	public:
		thread_man() {}
		
		void stop_all_threads()
		{
			for (int i = 0; i < threads.size(); i++)
			{
				threads[i].~jthread();
				threads.erase(threads.begin() + i);
			}	
		}

		void add_thread(std::function<void(std::stop_token, std::string, int)> func, std::string arg1, int arg2)
		{
			threads.emplace_back(func, arg1, arg2);	
		}

		void stop_thread(int index)
		{
			if (index < threads.size())
				threads[index].request_stop();
		}
	private:
		std::vector<std::jthread> threads;
};