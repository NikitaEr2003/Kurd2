#pragma once
#include "SafeQueue.h"
#include <vector>
#include <functional>
class ThreadPool {
 public:
	ThreadPool(size_t Size);

 
    static int СountFunc;

	size_t vector_size;

	SafeQueue<std::function<void()>> m_queue;

	std::vector <std::thread> m_vector;

	std::function<void()> work();


    void submit(const std::function<void()> func);

	void start();
   
           

	~ThreadPool();

};

