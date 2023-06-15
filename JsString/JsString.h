#include <stdio.h>
#include <string.h>
#include <stdlib.h>


        //at and charat
char charAt(char* arr, int index)
{
    int size = strlen(arr);
    index = index < 0 ? size + index : index;
    if (index < 0 || index >= size)
    {
        puts("Invalid index");
    }
    else
    { 
        return arr[index];
    }

    return ' ';
    
}

int charCodeAt(char* arr, int index)
{
    if (index < 0 || index >= strlen(arr))
    {
        puts("Invalid index");
    }

    else
    {
        int charcode = (int)arr[index];
        return charcode;
    }
    return ' ';

}

char* concat(const char* this, const char* rhs1, const char* rhs2)
{
    int size1 = strlen(this); //this
    int size2 = strlen(rhs1); //rhs1
    int size3 = strlen(rhs2); //rhs2

    char* newarr = (char*)calloc(size1 + size2 + size3 + 1, sizeof(char));
    for (int i = 0; i < size1; ++i)
    {
        newarr[i] = this[i];
    }

    for (int i = 0; i < size2; ++i)
    {
        newarr[size1] = rhs1[i];
        ++size1;
    }

    for (int i = 0; i < size3; ++i)
    {
        newarr[size1] = rhs2[i];
        ++size1;
    }

    newarr[size1 + size2] = '\0';

    return newarr;
}

int endsWith(const char* arr, char* word)
{
    int size = strlen(arr);
    int index = size - 1;
    for (int i = strlen(word) - 1; i >= 0; --i)
    {
        if (arr[index] != word[i])
        {
            return 0;
        }
        index--;
    }

    return 1;
}

int endsWith_int(const char* arr, char* word, int pos)
{
    int size = strlen(arr);
    int index = pos;
    for (int i = strlen(word) - 1; i >= 0; --i)
    {
        if (arr[index] != word[i])
        {
            return 0;
        }
        index--;
    }

    return 1;
    
}

int includes(const char* arr, const char* word)
{
    int size1 = strlen(arr);
    int size2 = strlen(word);
    int index = 0;
    int countOfCorrect = 0;
    for (int i = 0; i < size1; ++i)
    {
        if (countOfCorrect == size2)
        {
            return 1;
        }
        
        if (arr[i] == word[index])
        {
            ++countOfCorrect;
            ++index;
        }

        else
        {
            index = 0;
            countOfCorrect = 0;
        }
    }

    return 0;
    
}

int indexOf(const char* arr, const char* word)
{
    int size1 = strlen(arr);
    int size2 = strlen(word);
    int index = 0;
    int countOfCorrect = 0;
    for (int i = 0; i < size1 + 1; ++i)
    {
        if (countOfCorrect == size2)
        {
            return i - countOfCorrect;
        }
        
        if (arr[i] == word[index])
        {
            ++countOfCorrect;
            ++index;
        }

        else
        {
            index = 0;
            countOfCorrect = 0;
        }
    }

    return 0;
    
}

int indexOf_int(const char* arr, const char* word, int pos)
{
    int size1 = strlen(arr);
    int size2 = strlen(word);
    int index = 0;
    int countOfCorrect = 0;
    for (int i = pos; i < size1 + 1; ++i)
    {
        if (countOfCorrect == size2)
        {
            return i - countOfCorrect;
        }
        
        if (arr[i] == word[index])
        {
            ++countOfCorrect;
            ++index;
        }

        else
        {
            index = 0;
            countOfCorrect = 0;
        }
    }

    return 0;
    
}

int lastIndexOf(const char* arr, const char* word)
{
    int size2 = strlen(word);    
    int index = size2;
    int countOfCorrect = 0;
    
    for (int i = strlen(arr); i >= 0; --i)
    {
        if (countOfCorrect == size2)
        {
            return i;
        }
        
        if (arr[i] == word[index])
        {
            ++countOfCorrect;
            --index;
        }
            
    }
    
    return 0;
}

char* padEnd(char* arr, int newsize, char* arr2)
{
    int size1 = strlen(arr);
    if (newsize <= size1)
    {
        return arr;
    }
    char* tmp = (char*)calloc(newsize, sizeof(char));

    strcat(tmp, arr);

    for (int i = 0; i < newsize - size1; i++)
    {
        strcat(tmp, arr2);
    }
   

   return tmp;
}

char* padStart(char* arr, int newSize, char* arr2)
{
    int size1 = strlen(arr);
    int size2 = strlen(arr2);
    if (newSize <= size1)
    {
        return arr;
    }
    char* tmp = (char*)calloc(newSize + 1, sizeof(char));
    
    for (int i = 0; i < newSize - size1; i++)
    {
        strcat(tmp, arr2);
    }

    strcat(tmp, arr);
    
    return tmp;

}

char* repeat(char* arr, int count)
{
    int size = strlen(arr);

    char* tmp = (char*)calloc(count, size);

    for (int i = 0; i < count; ++i)
    {
        strcat(tmp, arr);
    }
    
    return tmp;
}

char* replace(char* arr, char* word1, char* word2)
{
    int size1 = strlen(word1);
    int size2 = strlen(word2);

    char* tmp = (char*)calloc(size1 + size2, sizeof(char));
    strcpy(tmp, arr);
    int index = indexOf(arr, word1);
    for (int i = 0; i < size2; ++i)
    {
        tmp[index++] = word2[i];
    }
    
    return tmp;
    
}

char* replaceAll(char* arr, char* word1, char* word2)
{
    int size1 = strlen(word1);
    int size2 = strlen(word2);

    char* tmp = (char*)calloc(size1 + size2, sizeof(char));
    strcpy(tmp, arr);
    for (int i = 0; i < size1 + size2; i++)
    {
        int index = indexOf(tmp, word1);
        for (int i = 0; i < size2; ++i)
        {
            tmp[index++] = word2[i];
        }
    }
    return tmp;
}

char* slice(char* arr, int num)
{
    int size = strlen(arr);

    if (num < 0 || num >= size)
    {
        return arr;
    }
    
    char* tmp = (char*)calloc(size - num, sizeof(char));

    int index = 0;
    for (int i = num; i < size; i++)
    {
        tmp[index++] = arr[i];
    }
    
    return tmp;
}

// split

int startsWith(char* array, char* word)
{
    int size1 = strlen(array);
    int size2 = strlen(word);

    for (int i = 0; i < size2; ++i)
    {
        if (array[i] != word[i] || size1 < size2)
        {
            return 0;
        }
    }
    return 1;
}

char* toLowerCase(char* arr)
{
    int size = strlen(arr);
    char* tmp = calloc(size, sizeof(char));
    strcpy(tmp, arr);
    for (int i = 0; i < size; ++i)
    {
        if (tmp[i] >= 'A' &&  tmp[i] <= 'Z')
        {
            tmp[i] += 32;
        }
        
        
    }
    
    return tmp;
}

char* toUpperCase(char* arr)
{
    int size = strlen(arr);
    char* tmp = calloc(size, sizeof(char));
    strcpy(tmp, arr);
    for (int i = 0; i < size; ++i)
    {
        if (tmp[i] >= 'a' &&  tmp[i] <= 'z')
        {
            tmp[i] -= 32;
        }
        
        
    }
    
    return tmp;
}