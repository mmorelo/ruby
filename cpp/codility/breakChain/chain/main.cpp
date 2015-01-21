#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


int find_min_forward(int min, vector<int> v)
{
    for( size_t i = 0; i< v.size(); i++)
    {
        if( v[i] == min)
            return i;
    }
    return -1;
}

int find_min_backwards(int min, vector<int> v)
{
    for( size_t i = v.size() - 1; i>=0 ; i--)
    {
        if( v[i] == min)
            return i;
    }
    return -1;
}

int solution(vector<int> &A)
{
    //Create vector of minimums

    vector<int>B;
    vector<int>C;
    int min_left= 10000;
    int min_right= 10000;

    size_t lower_index = 1;
    size_t upper_index = A.size() - 2;

    size_t j = upper_index;

    for( size_t i = lower_index ; i <= upper_index ; i++ )
    {
        if( A[i] < min_left )
        {
            min_left = A[i];
        }
        if( A[j] < min_right )
        {
            min_right = A[j];
        }

        B.push_back( min_left );
        C.insert( C.begin(), min_right );
        j--;
    }

    //First option

    int min_b = *std::min_element( B.begin(), B.end());
    //Find first appearance of min in B
    size_t index_in_b = find_min_forward(min_b, B);


    int cost_in_c = 100000;
    if( index_in_b + 2 < C.size( ) )
    {
    cost_in_c = *std::min_element( C.begin()+index_in_b + 2, C.end() );
    }

    int option1_cost = cost_in_c + min_b;


    //Second option, same but C as reference

    int min_c = *std::min_element( C.begin(), C.end());
    //Find first appearance of min in B
    size_t index_in_c = find_min_backwards(min_c, C);

    int cost_in_b=100000;

    if( B.size() -1 - index_in_c  - 2 > 1 )
    {
     cost_in_b = *std::min_element( B.begin(), B.end() - ( B.size() -1 - index_in_c ) - 2 );
    }

    int option2_cost = cost_in_b + min_c;

    return option1_cost < option2_cost ? option1_cost : option2_cost;


}




int main(int argc, char *argv[])
{


    vector<int> A;

    A.push_back( 0 );
    A.push_back( 6 );
    A.push_back( 1 );
    A.push_back( 2 );
    A.push_back( 1 );
    A.push_back( 0 );


 cout << solution(A) << endl;


}
