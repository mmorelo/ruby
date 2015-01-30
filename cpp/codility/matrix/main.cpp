#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool in_range( int i, int j,  int rows, int columns )
{

    if( i < 0 || j < 0)
        return false;

    if( i > rows -1  || j > columns -1 )
        return false;

    return true;
}

int search( const vector< vector <int> >& matrix, int i, int j, int element, int rows, int columns, int indices )
{
    //Base case
    if( indices < 0 || !in_range( i, j, rows, columns ) )
        return 0;


    int found = 0;
    if( matrix[i][j] == element )
    {
           found = 1;
    }

    return found + search( matrix, i-1, j, element, rows, columns, indices - 1 ) +
                  search( matrix, i, j-1, element, rows, columns, indices - 1 ) +
                  search( matrix, i + 1, j, element, rows, columns, indices - 1 ) +
                  search( matrix, i, j + 1, element, rows, columns, indices - 1 );


}

int main(int argc, char * argv[]) {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int rows = 0;
    int columns = 0;





rows = 2;

string line1 = "1 2 9 8 3";
string line2 = "3 4 12 25 5";


vector<int> aux;
 vector< vector<int> > m(rows);
 for( size_t i = 0; i < rows; i++ )
 {

  string delimiter = " ";
  size_t pos = 0;
  string part= "";
  int number;
  line1 = line1 + string(" ");
  aux.clear();

     while( (pos = line1.find( delimiter )) != string::npos )
     {
        part = line1.substr(0, pos);

        stringstream ( part ) >> number;
        aux.push_back(number);
         line1.erase(0, pos+1);
     }


     m[i] = aux;

line1 = line2;
 }

 columns = aux.size();



    //cout <<"columns" << columns << endl;

 // get indices
    /*
 string str_indices;
 cin >> str_indices;
 int indices;
 stringstream ( str_indices ) >> indices;
 */
    int indices = 2;


//empty matrix
  if( rows == 0 || columns == 0)
  {
    cout << "NO" << endl;
    return 0;
  }



  for( size_t i = 0 ; i < rows; i++ )
  {
    for( size_t j = 0 ; j < columns; j++ )
    {
        if( search( m, i, j, m[i][j], rows, columns, indices ) > 1 )
        {
            cout << m[i][j] << endl;
            cout << "YES" << endl;
            return 0;
        }
    }
  }
  cout << "NO" << endl;


return 0;

}
