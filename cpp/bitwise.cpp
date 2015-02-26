#include <iostream>
#include <bitset>

using namespace std;

int solution(int N) {
    // write your code in C++98
    
    int result = N;
    int max = 0;
    for(int i = 1; i < 30; i++)
    {
        int val = (N << i & 0x3fffffff) | N >> (30-i);
        if(val > max)
        {
             max = val;
             result = 30-i;
        }
    }
    return result;
}

int main( int arc, char *argv[])
{
    int n = 51;
std::bitset<30> b(n);

cout << b << endl; 

    n = n << 29 & 0x3fffffff;

    cout << n << endl;

    n = n & 0x3fffffff;

    std::bitset<30> c( n);

    cout << c << endl;  

cout << n << endl;


}