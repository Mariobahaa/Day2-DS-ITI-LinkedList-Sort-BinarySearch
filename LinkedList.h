#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

template<class T>
class LinkedList
{
    Node<T> *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    //T ret *... in main remove * from cout, make fn ret T instead of *T
    T*getHead(){
        if(head==NULL) return NULL;
        return head->Data;
    }
    //T ret *... in main remove * from cout, make fn ret T instead of *T
    T*getTail(){
        if(tail==NULL) return NULL;
        return tail->Data;
    }
    //void Add(Node *newNode);

    void Add(T *data)
    {
        Node<T> *newNode = new Node<T>(data);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->Next = newNode;
            newNode->Prev = tail;
            tail = newNode;
        }
    }

    void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            cout << *(current->Data) << endl;
            current = current->Next;
        }
    }

    void Delete(T *data)
    {
        Node<T> *pDelete = Search(data);

        if(pDelete == NULL)
            return;

        if(pDelete == head)
        {
            if(pDelete == tail) // if(head->Next == NULL)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(pDelete == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next; // A->Next = B
            pDelete->Next->Prev = pDelete->Prev; // B->Prev = A
        }

        delete pDelete;
    }

    void InsertAfter(T *afterData, T *newData)
    {
        Node<T> *current;
        Node<T> *newNode = new Node<T>(newData);

        current = Search(afterData);
        if(current == NULL) return;
                    if(current==tail){
                        Add(newData);
                    }
                    else{
                        current->Next->Prev = newNode;
                        newNode->Next =current->Next;
                        current->Next = newNode;
                        newNode->Prev = current;
                        return;
                    }


    }

    void DeleteByIndex(int index)
    {
        Node<T> *pDelete = Search(index);

        if(pDelete == NULL)
            return;

        if(pDelete == head)
        {
            if(pDelete == tail) // if(head->Next == NULL)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(pDelete == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next; // A->Next = B
            pDelete->Next->Prev = pDelete->Prev; // B->Prev = A
        }

        delete pDelete;
    }

    void Reverse()
    {
        Node<T> *current = head;
        while(current!=NULL){
            Node<T>*temp = current->Next;
            current->Next = current->Prev;
            current->Prev = temp;
            current = temp;
        }
        Node<T>*temp = head;
        head = tail;
        tail = head;
    }

    void bubbleSort(int size)
    {
        for(int j=0;j<size;j++)
        {
            Node<T>*current = head;
            for(int i=0;i<size-1-j;i++)
            {
                if(*current->Data > *current->Next->Data)
                {
                    Swap(current,current->Next);
                }
            }
        }
    }
private:
    //Easy Swap
    void Swap(Node<T>*Node1, Node<T>*Node2){
        Node<T>*temp=Delete(Node1);
        InsertAfter(Node2,temp);
    }
    //Doing it the hard way (Not changing data)
    void Swap(Node<T>*Node1, Node<T>*Node2){
        Node<T>*temp = Node2;

        Node2 = Node1;
        Node2->Prev = Node1->Prev;
        Node2->Next = Node1;

        Node1 = temp;
        Node1->Prev=Node2;
        Node1->Next=temp->Next;
    }
    Node<T>* Search(T *data)
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            if(current->Data == data)
                return current;

            current = current->Next;
        }

        return NULL;
    }

    Node<T>* Search(int ind)
    {
        if(ind <0) return NULL;
        Node<T> *current = head;

        while(ind!=0 || current==NULL)
        {
            current = current->Next;
            ind--;
        }

        return current;
    }

};



#endif // LINKEDLIST_H
