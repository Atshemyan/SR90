#include "JsFunctions.h"

int main(int argc, char const *argv[])
{

    int arr[] = { 1, 2, 3, 4, 5, 6 };
    
    int size1 = sizeof(arr) / sizeof(int);
    int* arr2 = calloc(size1, sizeof(int));
    for (int i = 0; i < size1; i++)
    {
        arr2[i] = arr[i];
    }
    
    splice(arr2, size1, 1, 2, 9);

    for (int i = 0; i < size1; i++)
    {
        printf("%i ", arr[i]);
    }
    


    //         Sort Main        //
    // int arr[] = { 1, 30, 4, 9, 21, 100000, 20000, 30000 };
    // int size1 = sizeof(arr) / sizeof(int);
    // sort(arr, size1);
    // for (int i = 0; i < size1; ++i)
    // {
    //     printf("%i ", arr[i]);
    // }
    
    //            Slice             //
    // int arr[] = { 1, 2, 3, -4, 2, 1, 7 };
    // int size1 = sizeof(arr) / sizeof(int);
    // int minumum;
    // int* another = slice_double_index(arr, &size1, -2, 1);
    // for (int i = 0; i < size1; ++i)
    // {
    //     printf("%i ", another[i]);
    // }
    
      //     Reverce Main   //
    // int arr[] = { 1, 2, 3, 4, 2, 1, 7 };
    // int size1 = sizeof(arr) / sizeof(int);
    // int* another = reverce(&arr, size1);
    // for (int i = 0; i < size1; ++i)
    // {
    //     printf("%i ", another[i]);
    // }

    //         Last Index of Main         //
    // int arr[] = { 1, 2, 3, 4, 2, 1, 7 };
    // int size1 = sizeof(arr) / sizeof(int);
    // printf("%i", lastindexof(&arr, size1, 2));

    //            IndexOf 2 versions Main              // 
    // int arr[] = { 1, 2, 3, 4, 0, 1, 7 };
    // int size1 = sizeof(arr) / sizeof(int);
    // printf("%i", indexof_position(&arr, size1, 1, 2));

        //            filter_Main              //   
    // int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    // int size1 = sizeof(arr) / sizeof(int);
    // int* arrp = arr;
    // int newsize = 0;
    // int* newarr = filter(arrp, size1, &Function, &newsize);
    // for (int i = 0; i < newsize; i++)
    // {
    //     printf("%i ", newarr[i]);
    // }
    
        //            every_Main              //
    // int arr[] = { 120, 2, 39 , 3, 4, 5, 6, 9};
    // int* arrp = arr;
    // int size1 = sizeof(arr) / sizeof(int);
    // printf("%i", every(arrp, size1, &IsPoqrQarasun));
    
    //            Concat_Main              //
    // int arr[] = { 1, 2, 3, 4, 5, 6, 7};
    // int arr2[] = {2, 3, 4, 5, 6};
    // int* arrp = arr;
    // int* arrp2 = arr2;
    // int size1 = sizeof(arr) / sizeof(int);
    // int size2 = sizeof(arr2) / sizeof(int);
    // int* concated = concat(arrp, arrp2, size1 , size2);
    // for (int i = 0; i < size1 + size2; i++)
    // {
    //     printf("%i ", concated[i]);
    // }

    
    return 0;
}
