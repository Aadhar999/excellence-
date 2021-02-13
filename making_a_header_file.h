#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

// When we use structure normally we access the structure members using . operator 
// But when we use structure with a pointer then we use arrow(->) operator to access the structure members.

struct Array
{
    int A[15];
    int size;
    int length;
};

void traversal(Array obj)
{
    cout<<"Elements of array are : "<<endl;
    for(int i = 0; i <obj.length;i++)
        cout<<obj.A[i]<<",";
}

void append(Array *obj,int x)
{
    if(obj->length < obj->size)
        obj->A[obj->length] = x;
        obj->length++;
}

void insert(Array *obj,int index,int x)
{
    for(int i = obj->length; i > index;i--)
    {
        obj->A[i] = obj->A[i-1];
    }
    obj->A[index] = x;
    obj->length++;
}

void deletion(Array *obj,int index)
{
    for(int i = index; i < obj->length-1;i++)
    {
        obj->A[i] = obj->A[i+1];
    }
    obj->length--;
}

int linear_search(Array obj,int key)
{
    for(int i = 0;i<obj.length;i++)
    {
        if(obj.A[i] == key)
            return i;
    }
    return -1;
}

int bin_search(Array obj,int key)
{
    // iterative procedure
    int low = 0;
    int high = obj.length-1;
    static int counter;
    while(low <= high)
    {
        int mid = floor((low + high)/2);
        counter++;
        if(obj.A[mid] == key)
        {   cout<<"Total comparison done : "<<counter<<endl;
            return mid;
        }
        else if(key < obj.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout<<"Total comparison done : "<<counter<<endl;
    return -1;
}

int get(Array obj, int index)
{
    if(index>=0 && index<obj.length)
    {
        return obj.A[index];
    }
    else
        return -1;
}

void set(Array *obj,int index,int element)
{
    if(index>=0 && index<obj->length)
    {
        obj->A[index] = element;
    }

}

int max(Array obj)
{
    int max = obj.A[0];
    for(int i = 0; i < obj.length;i++)
    {
        if(obj.A[i] > max)
        {
            max = obj.A[i];
        }
    }
    return max;

}

int min(Array obj)
{
    int max = obj.A[0];
    for(int i = 0; i < obj.length;i++)
    {
        if(obj.A[i] < max)
        {
            max = obj.A[i];
        }
    }
    return max;

}

int sum(Array obj)
{
    int total = 0;
    for(int i = 0; i < obj.length;i++)
    {
        total += obj.A[i];
    }
    return total;
}

int average(Array obj)
{
    int total = 0;
    for(int i = 0; i < obj.length;i++)
    {
        total += obj.A[i];
    }
    return (total/obj.length);
}

// reversing an Array
// 1. method -- making an another array (auxilary array) and then copy from last of original array to this and finally copy this to original array

void reverse1(Array *obj)
{
    int aux[obj->size];
    for(int i = obj->length-1 ,j = 0; i >= 0; i--, j++)
    {
        aux[j] = obj->A[i];
    }

    for(int i = 0; i < obj->length; i++)
    {
        obj->A[i] = aux[i];
    }
}

// reversing an array
// 2nd method ------

void reverse2(Array *obj)
{
    for(int i = 0, j = obj->length-1;i<j;i++,j--)
    {
        swap(obj->A[i],obj->A[j]); // using premade swap function for this 
    }
}

void left_shift(Array *obj)
{
    for(int i = 0; i < obj->length;i++)
    {
        if(i<obj->length-1)
            obj->A[i] = obj->A[i+1];
        else
        {
            obj->A[i] = 0;
        }
        
    }
}

// improving linear_search

int imp_linear_search(Array *obj,int key)
{
    // transposition method
    for(int i = 0; i < obj->length;i++)
    {
        if(obj->A[i] == key)
        {
            swap(obj->A[i],obj->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int more_imp_linear_search(Array *obj,int key)
{
    // move to head method
    for(int i = 0; i < obj->length;i++)
    {
        if(obj->A[i] == key)
        {
            swap(obj->A[i],obj->A[0]);
            return 0;
        }
    }
    return -1;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

