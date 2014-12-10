#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>


using namespace std;

mutex mtx;
condition_variable cv;
int current = 0;
bool ready = false;

bool waiting = false;

bool have_to_speak = false;


enum Status {
    RUNNING,
    NOT_RUNNING
};


Status s=NOT_RUNNING;

void print( )
{


    cout << "print LOCKED mutex" << endl;

    while( s == RUNNING )
    {
        mtx.lock( );
        bool speak = have_to_speak;
        mtx.unlock( );

        cout << "Passed while" << endl;
        if( speak )
        {

            mtx.lock( );
            cout << "if locked mutex" << endl;
            have_to_speak = false;
            mtx.unlock();
            cout << "if RELEASED mutex" << endl;

            cout << "Hey" << endl;

            //cout << "HAve to speak ==== " << have_to_speak << endl;

            //cout << "Hey, wants to lock mutex" << endl;




        }
        else
        {

            mtx.lock( );
            cout << "ELSE locked mutex" << endl;
            //cout << "setting waiting true " << endl;
            waiting = true;
            //cout << "after setting waiting true " << endl;
            mtx.unlock( );
            cout << "ELSE RELEASED mutex" << endl;
            // Wait for condition have_to_speak
            std::unique_lock<std::mutex> lk(mtx);
            cout << "waiting " << endl;
            cv.wait( lk, []{return have_to_speak || !waiting;} );
            cout << "woke up" << endl;




        }
    }

    cout << "Quitting print" << endl;

}
/*
void run()
{
    unique_lock<mutex> lck(mtx);
    ready = true;
    cv.notify_all();

}
*/

void stop(thread& t)
{
    cout << "Stopped want to get lock" << endl;
    mtx.lock( );
    cout << "Stopped locked mutex" << endl;
    s = NOT_RUNNING;

    if(waiting)
    {
        cout << "setting waiting false " << endl;
        waiting = false;
        cout << "after waiting false " << endl;
        mtx.unlock();
        cv.notify_all( );

    }

 mtx.unlock();
    cout << "STOP RELEASED mutex" << endl;
cout << "before join" << endl;
    t.join();

}

void  foo( )
{
    mtx.lock();
    s = RUNNING;
    mtx.unlock();

    thread t=thread(print);

    for( size_t i = 0; i < 10; ++i)
    {
        if( i % 2 == 0 )
        {
            cout << "Inside if, want to get lock" << endl;
            mtx.lock( );
            cout << "FORIF locked" << endl;
            have_to_speak = true;
            mtx.unlock( );
            cout << "FORIF RELEASED" << endl;
            cv.notify_all( );
            //std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
        }
    }

    cout << "Before calling stop " << endl;
    stop(t);



}

int main()
{
    //We have main who calls foo, who creates anothe thread running function print

    foo();




/*

    int threadnum = 5;
    thread th[5];
    for ( size_t i = 0 ; i < 5; ++i )
    {
        th[i] = thread(print, i, threadnum);
    }

 run( );

 for ( size_t i = 0 ; i < 5; ++i )
 {
     th[i].join();
 }
*/


    return 0;
}
