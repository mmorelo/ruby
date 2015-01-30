#include <QCoreApplication>
#include<vector>

using namespace std;


struct Position
{
    int i;
    int j;
    bool operator==( Position other ){ return i == other.i && j == other.j; }
};

Position get_next_position( Position p, int lower_limit, int upper_limit )
{
    Position res;
    if( p.i == lower_limit )
    {
        if( p.j == upper_limit )
        {
            res.i = p.i + 1;
            res.j = p.j;
        }
        else
        {
            res.i = p.i;
            res.j = p.j + 1;
        }

    }
    else if( p.i == upper_limit )
    {
        if( p.j == lower_limit )
        {
            res.i = p.i - 1;
            res.j = p.j;
        }
        else
        {
            res.i = p.i;
            res.j = p.j - 1;
        }

    }

    // in the middle
    else if( p.i < upper_limit )
    {
         if( p.j == lower_limit )
         {
             res.i = p.i - 1;
             res.j = p.j;
         }
         else
         {
             res.i = p.i + 1;
             res.j = p.j;
         }
    }

    return res;

}

void rotate( vector< vector <int> >& v, Position p, int element, int lower_limit, int upper_limit, Position initial, int counter )
{
    //Base case

    if( p == get_next_position( initial,lower_limit, upper_limit  ) && counter > 1 ) //check
        return;

    Position next = get_next_position( p, lower_limit, upper_limit );
    int next_element = v[next.i][next.j];
    //Move
    v[next.i][next.j] = element;
    counter++;
    rotate( v, next, next_element, lower_limit, upper_limit, initial, counter);
}



void shift( vector< vector <int> >& v, int lower_limit, int upper_limit )
{
    if( lower_limit >= upper_limit )
        return;

    Position p;
    p.i = lower_limit;
    p.j = lower_limit;

    rotate( v, p, v[p.i][p.j], lower_limit, upper_limit, p, 0 );

    shift( v, lower_limit + 1, upper_limit - 1 );
}


int main(int argc, char *argv[])
{
    vector< vector <int> > v;

    vector<int> aux;
    aux.push_back(1);
    aux.push_back(2);
    aux.push_back(3);
    aux.push_back(4);

    v.push_back( aux );

    aux.clear();
    aux.push_back(5);
    aux.push_back(6);
    aux.push_back(7);
aux.push_back(8);

    v.push_back( aux );

    aux.clear();
    aux.push_back(9);
    aux.push_back(10);
    aux.push_back(11);
    aux.push_back(12);

    v.push_back( aux );

    aux.clear();
    aux.push_back(13);
    aux.push_back(14);
    aux.push_back(15);
    aux.push_back(16);

    v.push_back( aux );

    int lower_limit = 0;
    int upper_limit = v[0].size( ) -1;


  shift( v, 0, v.size() -1 );



    return 0;
}
