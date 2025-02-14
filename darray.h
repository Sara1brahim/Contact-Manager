#ifndef DARRAY_H
#define DARRAY_H
#include <stdexcept>
#include <iostream>
using namespace std;
template <class T>
class Darray
{
private:
    int capacity, sizee;
    T *arr;
    void resizee(int New)
    {
        T *ptr = new T[New];
        for(int i=0; i<sizee; ++i)
        {
            ptr[i]=arr[i];
        }
        delete []arr;
        arr=ptr;
        capacity=New;

    }
public:

    Darray( int cap=2):capacity(cap),sizee(0)
    {
        arr = new T[capacity];
    }
    Darray operator =(const Darray&other)
    {
        if(this!=&other)
        {
            delete[] arr;
            capacity=other.capacity;
            sizee=other.sizee;
            arr = new T[capacity];
            for(int i=0; i<sizee; ++i)
            {
                arr[i]=other.arr[i];

            }
        }
    }
    void append (T element)
    {
        if(sizee>=capacity)
        {
            resizee(capacity*2);
        }
        arr[sizee++]=element;
    }
    void Insert(T elem, int index)
    {
        if(sizee<index)throw std::out_of_range("Index out of range");
        if (sizee >= capacity)
        {
            resizee(capacity *2);
        }
        for (int i = sizee; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = elem;
        sizee++;
    }
    void Remove()
    {
        sizee = sizee - 1;
        if(sizee<=capacity/4) resizee(capacity/2);
    }
    void Delete(int index)
    {
        if (index >= sizee)
        {
            throw std::overflow_error("Invalid\n");
        }

        for (int i = index; i < sizee; i++)
        {
            arr[i] = arr[i + 1];
        }
        sizee--;
        if(sizee<=capacity/4)resizee(capacity/2);
    }
    void clearr()
    {
        sizee=0;
        resizee(2);
    }
    T Get(int index)
    {
        if (index >= sizee)
        {
            throw std::overflow_error("Invalid\n");
        }
        cout <<endl;

        return arr[index];
    }
    int GetSize() const
    {
        cout << endl;
        return sizee;
    }
    void Reverse()
    {
        int start = 0;
        int End = sizee - 1;
        while (start < End)
        {
            T temp = arr[start];
            arr[start] = arr[End];
            arr[End] = temp;
            start++;
            End--;
        }
    }
    void BubbleSort()
    {
        for (int i = 0; i < sizee - 1; i++)
        {
            for (int j = 0; j < sizee - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    int LinearSearch(T elem)
    {
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] == elem)
                return i;
        }
        cout << endl;
        return -1; // not found
    }
    int  BinarySearch(T elem)
    {
        size_t low = 0, high = sizee - 1, mid = 0;
        while (low < high)
        {
            mid = (low + (high - low)) / 2;
            if (arr[mid] == elem)
            {
                return mid;
            }
            if (arr[mid] < elem)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << endl;
    }
    void print()
    {
        for(int i=0; i<sizee; i++)
        {
            cout<<arr[i];
            cout<<" ";
        }
    }
    ~Darray()
    {
        delete []arr;
    }
    T& operator[](int index)
    {
        if (index < 0  ||index >= sizee)
        {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    int getSize() const
    {
        return sizee;
    }
    void remove(int index)
    {
        if (index < 0 || index >= sizee)
        {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < sizee - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }
        --sizee;
    }
    void RemoveDuplicates()
    {
        if (sizee == 0) return;

        int NewSize = 1;

        for (int i = 1; i < sizee; i++)
        {
            if (!(arr[i] == arr[NewSize - 1]))
            {
                arr[NewSize] = arr[i];
                NewSize++;
            }
        }

        sizee = NewSize;

    }
};
#endif DARRAY
