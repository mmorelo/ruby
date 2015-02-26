#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main ( int argc, char * argv[])
{
 
    int N = 5;
    int n = N;
    int mask = 0;
    while( n )
    {
        n = n>>1;
        mask = mask<<1;
        mask +=1;
    }

            cout << "NEgati " << (bitset<32>) ~N  << "\n" << "MAsk   " << (bitset<32>)mask << endl;
            cout << "AND    " << (bitset<32>) (~N & mask) << endl;
 


}