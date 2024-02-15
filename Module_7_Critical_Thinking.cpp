#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool isCountDownStarted = false;

void countUp()
{
    for (int i = 1; i <= 20; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (isCountDownStarted)
        {
            cv.wait(lock);
        }
        std::cout << "Count Up: " << i << std::endl;
        if (i == 20)
        {
            isCountDownStarted = true;
            cv.notify_all();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay of 500 milliseconds
    }
}

void countDown()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(250)); // Delay of 250 milliseconds
    for (int i = 20; i >= 0; --i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (!isCountDownStarted)
        {
            cv.wait(lock);
        }
        std::cout << "Count Down: " << i << std::endl;
        if (i == 0)
        {
            cv.notify_all();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay of 500 milliseconds
    }
}

int main()
{
    std::thread thread1(countUp);
    std::thread thread2(countDown);

    thread1.join();
    thread2.join();

    std::cin.ignore();
    return 0;
}