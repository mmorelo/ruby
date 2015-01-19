

//typedef struct Node * List;


#include<iostream>

using namespace std;

struct Node
{
    int value;
    Node * next;

};

bool remove_value( Node * current, int value )
{
    if( current == 0 )
    {
        return false; //Not found
    }
    else if( current->value == value )
    {
            delete current;
            return true;
    }
    else if( current->next && current->next->value ==  value)
    {
        Node * n = current->next;
        current->next = n->next;
        delete n;
        return true;
    }


    return remove_value( current->next, value);


}



int main( int arc, char * argv[] )
{
    Node *a, *b;

    Node * head = NULL;
    a = new Node;
    a->value = 1;
    head = a;

    remove_value(head, 1);


    return 0;
}

