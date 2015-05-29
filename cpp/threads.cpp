#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
 
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i, j = 0;
 
bool function_cond() { return  i == 1 && j == 1;}

void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, function_cond); //[]{return i == 1 && j == 1;}
    std::cerr << "...finished waiting. i == 1\n";
}
 
void signals()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cerr << "Notifying...\n";
    }
    
 
    std::this_thread::sleep_for(std::chrono::seconds(1));
 
    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
        std::cerr << "Notifying again.. 2\n";
    }
    cv.notify_all();

    std::this_thread::sleep_for(std::chrono::seconds(1));
 
    {
        std::lock_guard<std::mutex> lk(cv_m);
        j = 1;
        std::cerr << "Notifying again 3\n";
    }
    cv.notify_all();

}

 
int main()
{
    std::thread t1(waits), t2(waits), t3(waits), t4(signals), t5(signals);
    t1.join(); 
    t2.join(); 
    t3.join();
    t4.join();
    t5.join();

}