#include <iostream>
using namespace std;

template<typename T> class Node
{
public:

    T content; //For any information that describes this node
    int data = 0; // Is the ID of each Node
    Node* next = NULL; //Th next Node connected

    /*
    This is the constructor, for creating new nodes
    */
    Node<T>(T t = (T)"")
    {
        content = t;
    }

    /*
    This method counts how much nodes are, doesn't need params
    */
    int size()
    {
        Node<T>* walked = this;
        int steps = 0;

        while (walked != NULL)
        {
            steps++;
            walked = walked->next;
        }
        return steps;
    }

    /*
    This method is for create new linked nodes
    opcionality you can add a param according
    type of value (int, char, string, etc)
    */
    void push_back(T t = (T)"")
    {
        Node* onpoint = this;
        for (int i = 0; i < this->size() - 1; i++)
        {
            onpoint = onpoint->next;
        }
        onpoint->next = new Node<T>(t);
        data += 1;
        onpoint->next->data = data;
    }
    /*
    This method return the node that you want for:
    -Creating a next node
    -Deleting the node (or the next node of this one)
    -Manipulating any information about this
    */
    Node<T>* at(int index)
    {
        Node<T>* atnode = this;

        for (int i = 0; i < index - 1; i++)
        {
            atnode = atnode->next;
        }
        return atnode;
    }

    ~Node<T>() {}
};

//This is an example struct, delete it if you want
struct alumno {
    string name;
    int ID, year;
    float average;
};

int main()
{
    //Using the alumno struct for example
    Node<alumno*>* alumnos = new Node<alumno*>();

    return 0;
}