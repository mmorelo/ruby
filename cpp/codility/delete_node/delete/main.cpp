

//typedef struct Node * List;

struct Node {

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



int main(int argc, char *argv[])
{
    Node a,b,c, d;

    a.value = 1;
    a.next = &b;
    b.value = 2;
    b.next = &c;

    c.value = 3;
    c.next = &d;
    d.value = 4;
    d.next = 0;


    int v = 1;


    remove_value( &a, v);

    //Print list



}
