#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}



void SelectionSort(int *arr, int size)
{
    int minIndex;

    for(int counter = 0; counter < size - 1 ; counter++)
    {
        minIndex = counter;
        for(int index = minIndex + 1 ; index < size; index++)
        {
            if(arr[index] < arr[minIndex])
                minIndex = index;
        }
        Swap(arr[counter], arr[minIndex]);
    }
}

void InsertionSort(int *arr, int size)
{
    int key, index;

    for(int counter = 1; counter < size; counter++)
    {
        key = arr[counter];
        index = counter - 1;

        while(index >=0 && arr[index] > key)
        {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = key;
    }
}

int BinarySearch(int *arr, int size, int num)
{
    int min = 0, max = size - 1, mid;

    while(min <= max)
    {
        mid = (min + max) / 2;

        if(num == arr[mid])
            return mid;

        if(num > arr[mid])
            min = mid + 1;
        else
            max = mid - 1;
    }

    return -1;
}

int main()
{
    LinkedList<int> L;
    L.Add(new int(3));
    L.Add(new int(2));
    L.Add(new int(4));
    L.Add(new int(1));
    L.bubbleSort(4);
    L.Display();

    return 0;
}
