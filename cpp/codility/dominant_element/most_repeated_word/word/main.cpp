#include<vector>
#include<map>
#include<string>
#include<iostream>

using namespace std;



void count_words(const vector<string>& words, const vector<string>& blacklist, map<string, int>& hash )
{
    //Prepare blacklist
    for( size_t i = 0; i < blacklist.size( );  i++ )
    {
        hash[blacklist[i]] = -1;
    }

    //count words
    for( size_t i = 0; i < words.size( );  i++ )
    {
        if ( hash.find(words[i]) == hash.end() )
        {
                hash[words[i]] = 1;
        }
        else if( hash[words[i]] != -1 )
        {
            hash[words[i]]++;
        }
    }
}


string find_max_repetitions( const map<string, int>& hash )
{
    string word;
    int max= 0;
    for( map<string, int>::const_iterator it = hash.begin( ); it != hash.end( ); ++it )
    {
        if( max < it->second)
        {
            word = it->first;
            max = it->second;
        }
    }

return word;

}



int main(int argc, char *argv[])
{

map<string, int> hash;

 vector<string> v;
 v.push_back("palabra");
 v.push_back("word");
 v.push_back("palabra");
 v.push_back("word");
 v.push_back("palabra");
 v.push_back("palabra");
 v.push_back("aaaa");

 vector<string> black;
 black.push_back("aaaa");


 count_words( v, black , hash );

 const string str =find_max_repetitions( hash );

    cout << str << endl;



}
