#include <iostream>

using namespace std;

void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void BubbleSort(int *arr, int size)
{
    int sorted = 0;
    for(int counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;
        for(int index = 0; index < size -1 - counter ; index++)
        {
            if(arr[index] > arr[index + 1])
            {
                Swap(arr[index], arr[index + 1]);
                sorted = 0;
            }
        }
    }
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
    int arr[] = {3, 2, 5, 4, 1};

    SelectionSort(arr, 5);

    int foundIndex = BinarySearch(arr, 5, 4);

    for(int index = 0; index < 5; index++)
    {
        cout << arr[index] << endl;
    }

    return 0;
}
