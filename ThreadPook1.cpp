#include "ThreadPool.h"
int ThreadPool::СountFunc = 0;
ThreadPool::ThreadPool(size_t Size) : vector_size(Size) {
  m_vector.resize(vector_size);

}

ThreadPool::~ThreadPool() {
  for (int i = 0; i < vector_size; i++) {
    if (m_vector[i].joinable())
    m_vector[i].join();
  }
}

void ThreadPool::submit(const std::function<void()> func) {
  m_queue.push(func);
  ThreadPool::СountFunc++;
}

std::function<void()> ThreadPool::work() {
  auto func = m_queue.pop();
  return func;
}

void ThreadPool::start() {
  for (int i = 0; i < СountFunc; i++) {
    m_vector[i] = std::thread(work());
  }
}