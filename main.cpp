#include <iostream>
#include "threadpool.h"

using namespace std;


int func(int answer)
{
    return answer;
}



int main()
{
    // create thread pool with 4 worker threads
    ThreadPool pool;

    pool.setWorkerSize(4);

    // enqueue and store future
    std::future<int> result0 = pool.pushWork(&func, 0);
    std::future<int> result1 = pool.pushWork(&func, 1);
    std::future<int> result2 = pool.pushWork(&func, 2);
    std::future<int> result3 = pool.pushWork(&func, 3);

    // get result from future
    std::cout << result0.get() << std::endl;
    std::cout << result1.get() << std::endl;
    std::cout << result2.get() << std::endl;
    std::cout << result3.get() << std::endl;


    return 0;
}
