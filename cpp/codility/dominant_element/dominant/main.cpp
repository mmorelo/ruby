
#include<vector>
#include<iostream>

using namespace std;

int select_candidate( const vector<int>& v )
{
    int selected;
    unsigned int count = 0;

    for( size_t i = 0; i < v.size( ); i++ )
    {
        if( count == 0)
        {
            selected = v[i];
            count++;
        }
        else if( selected == v[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return selected;
}


bool check_validity_of_selection( int selected, const vector<int>& v )
{
    unsigned int count = 0;

    for(size_t i = 0; i < v.size( ); i++ )
    {
        if( selected == v[i] )
        {
            count++;
        }
    }

    size_t size = v.size();

    return count >= float(size)/2;
}

int main(int argc, char *argv[])
{

  int arr[] = {1,2,5,4,5,5,6,23,2,58,5,5,5};
  vector<int> v( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  int candidate = select_candidate(v);
  if (check_validity_of_selection(candidate, v))
  {
      cout << "Element " << candidate << endl;
      return 0;
  }

      cout << "Not found" << endl;



}
