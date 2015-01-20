
#include<vector>
#include<iostream>

using namespace std;

int solution ( int x, vector<int>& A)
{
    int last_index_left, last_index_right;
    int last_counter_left, last_counter_right;

    int index_right = A.size() - 1;
    int index_left= 0;

    int counter_left = 0, counter_right = 0;

    while( index_right >= index_left )
    {
        if( x == A[ index_left ] )
        {
            counter_left++;
        }

        if( x != A[ index_right ])
        {
            counter_right++;
        }

        if( counter_left == counter_right )
        {
            last_index_left = index_left;
            last_index_right = index_right;
            last_counter_left = counter_left;
            last_counter_right = counter_right;
        }

        index_right--;
        index_left++;
    }

    //Check indexes
    if( counter_right == last_counter_left )
        return last_index_left;
    else if ( counter_left == last_counter_right )
        return last_index_right;
    else
        return 0;


}


int main(int argc, char *argv[])
{

vector<int> A;

A.push_back(5);
A.push_back(5);
A.push_back(1);
A.push_back(7);
A.push_back(2);
A.push_back(3);
A.push_back(5);

vector<int> B;
vector<int> C;
C.push_back(7);
C.push_back(2);




int x = 5;

 cout << solution(x, A ) << endl;
 cout << solution(x, B ) << endl;
  cout << solution(x, C ) << endl;


}
