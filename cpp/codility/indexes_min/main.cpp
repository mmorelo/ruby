

#include<QDebug>

#include<vector>
#include<map>
#include<utility>
#include <limits>
#include <iostream>
#include <algorithm>

using namespace std;

void generate_index_helper( const vector<int>& v, map<int,int>& indexes )
{
    indexes.clear();

    for( size_t i = 0; i< v.size(); ++i)
    {
        indexes[v.at(i)] = i;
    }
}

void find_minimum_distance( const vector<int>& v,  map<int,int>& indexes, int& index1, int& index2 )
{
    unsigned int min = std::numeric_limits<unsigned int>::max();

    for( size_t i = 0; i < v.size() -1; ++i )
    {
        if( v[i] == v[i + 1])
        {
            continue;
        }
        if( std::abs( v[i] - v[i + 1] ) < min )
        {
            min =  std::abs( v[i] - v[i + 1] );
            index1 = indexes[v[i]];
            index2 = indexes[v[i+1]];
        }


    }
}

int main ( int arc , char *argv[] )
{

 static const int arr[] = {55,5,1,9,6,88};
 vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );

 map<int, int> indexes;

 generate_index_helper( v, indexes );

 std::sort(v.begin(), v.end());

 int index1, index2;

 find_minimum_distance( v, indexes, index1, index2 );

 cout << "Indexes are " << index1 << "," << index2 << endl;


    return 0;
}


