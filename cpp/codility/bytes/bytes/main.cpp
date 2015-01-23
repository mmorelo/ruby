#include <QCoreApplication>
#include<string>
#include<iostream>
#include <sstream>  // Required for stringstreams

using namespace std;

#define DIVISOR 1000

string get_unit( unsigned int n)
{
    switch( n )
    {
        case(0): return "B";
    case(1): return "K";
    case(2): return "M";
    case(3): return "G";
    default:
        return "ERR";
    }

}



 string convert( unsigned int n)
 {
     unsigned int rest = 0;
     unsigned int counter = 0;
     std::ostringstream oss;

     while ( n > DIVISOR )
     {
         rest = n % DIVISOR;
         n =  n / DIVISOR;
         counter++;
     }

    string out;
    string decimal_part = "";

    oss << rest;
    string rest_string = oss.str();

    oss.flush();

    if( rest )
    {
        if( rest < 10  )
        {
            decimal_part = "."  + rest_string[0];
        }
        else
        {
            decimal_part = string(".")  + rest_string[0] + rest_string[1];
        }
    }
     std::ostringstream oss2;
        oss2 << n;
     out = oss2.str( ) + decimal_part + get_unit( counter );


 }


int main(int argc, char *argv[])
{

    cout << convert(5245199) << endl;

    return 0;

}
