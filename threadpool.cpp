#include "threadpool.h"



ThreadPool::ThreadPool()
{

}



void ThreadPool::setWorkerSize(int Size)
{

    for(int i=0; i < Size; i++)
    {

        std::cout << "Thread " << i << "created" << std::endl;

        while(1)
        {
            Workers_.emplace_back([=]()
            {

                int thread_id = i;

                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> ul(lock);

                    Condition_.wait(ul, [=]{ return !Tasks_.empty(); });

                    task = std::move(Tasks_.front());
                    Tasks_.pop();
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                }

                std::cout << "Thread " << thread_id << " is working" << std::endl;

                task();

            });
        }
    }

}

