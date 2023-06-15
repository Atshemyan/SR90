#include <stdlib.h>
#include <stdio.h>
int* concat(int* arr1, int* arr2, int size1, int size2)
{
    int* tmp = calloc(sizeof(int), size1 + size2);
    unsigned int IndexForTmp = 0;
    for (int i = 0; i < size1; i++)
    {
        tmp[IndexForTmp++] = arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        tmp[IndexForTmp++] = arr2[i];
    }
    
    return tmp;
    
}

int every(int* arr, int size1 ,int (*function_ptr)(int a))
{
    for (int i = 0; i < size1; i++)
    {
        if (function_ptr(arr[i]) == 0)
        {
            return 0;
        }
        
    }

    return 1;
    
}

int* filter(int* arr, int size1 ,int (*function_ptr)(int a), int* newsize)
{
    *newsize = 0;

    for (int i = 0; i < size1; i++)
    {
        if (function_ptr(arr[i]) == 1)
        {
            (*newsize)++;
        }
    }

    int* tmp = calloc(*newsize, sizeof(int));
    unsigned int index = 0;
    for (int i = 0; i < size1; i++)
    {
        if (function_ptr(arr[i]) == 1)
        {
            tmp[index++] = arr[i];
        }
    }
    
    return tmp;
}

void foreach(int* arr, int size, void (*callback)(int))
{
    for (int i = 0; i < size; ++i)
    {
        callback(arr[i]);
    }
}

int indexof(int* arr, int size, int number)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == number)
        {
            return i;
        }
        
    }

    return -1;
    
}

int indexof_position(int* arr, int size, int number, int position)
{
    int match = 0;
    for (int i = 0; i < size; ++i)
    {
        if (position == match)
        {
            return i - 1;
        }
        
        if (arr[i] == number)
        {
            ++match;
        }
        
    }
    
    return -1;
    
}

int lastindexof(int* arr, int size, int value)
{
    unsigned int saver = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == value)
        {
            saver = i;
        }
        
    }

    return saver;
    
}

void map(int* arr, int size, void (*callback)(int))
{
    foreach(arr, size, callback);
}

int* reverce(int* arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {   
        int tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }

    int* another = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        another[i] = arr[i];
    }

    return another;
    
    
}

int* slice(int* arr, int size)
{
    int* another = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        another[i] = arr[i];
    }
    return another;        
}

int* slice_single_index(int* arr, int* size, int index)
{

    if (index < 0)
    {
        index = (*size) + index; 
    }
    
    int* another = calloc((*size) -= index, sizeof(int));

    for (int i = index + 1; i < *size; ++i)
    {   
        another[i] = arr[i];
    }

    return another; 
    
}

int* slice_double_index(int* arr, int* size, int index1, int index2)
{
    if (index1 < 0)
    {
        index1 = *size + index1;
    }
    
    if (index2 < 0)
    {
        index2 = *size + index2;
    }

    int max = index1 > index2 ? index1 : index2;
    int min = index1 < index2 ? index1 : index2;
    
    
    int* another = calloc(max - min, sizeof(int));
    unsigned int index = 0;
    for (int i = min; i < max; ++i)
    {   
        another[index++] = arr[i];
    }
    *size = max - min;
    return another; 

}

int some(int* arr, int size ,int (*function_ptr)(int a))
{
    for (int i = 0; i < size; i++)
    {
        if (function_ptr(arr[i]) == 1)
        {
            return 1;
        }
        
    }

    return 0;
    
}

void sort(int* arr, int size)
{
    int* symarr = calloc(size, sizeof(arr));
    unsigned int index_sym = 0;
    int symbol = 0;
    for (int i = 0; i < size; ++i)
    {
        int copy = arr[i];

        do
        {
            symbol = copy % 10;
            copy /= 10;
        }
        while (copy != 0);

        symarr[index_sym++] = symbol;

    }
    
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (symarr[j] <= symarr[i])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                tmp = symarr[i];
                symarr[i] = symarr[j];
                symarr[j] = tmp;
                
            }
        }
    }
}

void splice(int* arr, int size, int index, int howanydelete, int value)
{
    
    arr = realloc(arr, size + 1);
    
    
    
    int i = size;
    while (howanydelete)
    {
        if (i <= index + 1)
        {
            break;
        }
        arr[i - 1] = arr[i];
        --i;
        howanydelete--;
        arr = realloc(arr, size - 1);
        --size;
    }

}