#include <iostream>
#include <vector>

using namespace std;








int main ( int argc, char * argv[])
{
    int M = 5;
    int N = 10;

    vector< vector< int > > matrix;

    matrix.resize( M );

    for (int i = 0; i < matrix.size( ); ++i)
    {
        matrix[i].resize(N);

    }


    for (int i = 0; i < matrix.size() ; ++i)
    {
        for (int j = 0; j < matrix[0].size( ); ++j)
        {
            cout << "Matrix " << i << " " << j << " = " << matrix[i][j] << endl;
        }
    }

}