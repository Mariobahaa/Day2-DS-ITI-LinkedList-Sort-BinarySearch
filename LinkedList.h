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

    void bubbleSort(int Size)
    {
        if(Size<2) return;
        int sorted = 0;
        for(int ind=0;(ind<Size) && !sorted;ind++)
        {
            Node<T>*current = head;
            sorted =1;
            for(int i=0;i<Size-1-ind;i++)
            {
                if(current == NULL) break;
                if(*current->Data > *current->Next->Data)
                {
                    Swap(current,current->Next);
                    sorted=0;
                    //current= current->Prev;
                }
                current = current->Next;
            }

        }
    }

    void selectionSort(int Size)
    {
        if(Size<2) return;
        Node<T>*pos = head;
        int cnt=0;
        for(int i=0;i<Size-1;i++){
            Node<T>* mini=pos;
            Node<T>*current=pos->Next;
            for(int j=i+1;j<Size;j++)
            {
                if(*current->Data<*mini->Data){
                    mini = current;
                }
                current = current->Next;
            }

            if(mini!=pos){
                Swap(pos,mini);
            }

            pos=pos->Next;
        }


    }

T*binarySearch(T data, int Size){
    selectionSort(Size);
    int mini = 0, maxi = Size - 1, mid;
    int curr = 0;
    Node<T>*midNode = head;
    while(mini <= maxi)
    {
        mid = (mini + maxi) / 2;
        if(curr<mid){
            for(int i=0;i<mid-curr;i++)
                midNode = midNode->Next;

            curr = mid;
        }
        else if(curr>mid){
            for(int i=0;i<curr-mid;i++)
                midNode = midNode->Prev;

            curr = mid;
        }

        if(data == *midNode->Data)
            return midNode->Data;

        if(data > *midNode->Data)
            mini = mid + 1;
        else
            maxi = mid - 1;
    }

    return NULL;
}
private:

    void Swap(Node<T>*Node1, Node<T>*Node2){
        T*temp = Node2->Data;
        Node2->Data = Node1->Data;
        Node1->Data = temp;
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
