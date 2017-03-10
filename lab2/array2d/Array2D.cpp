//
// Created by bienking on 07.03.17.
//

#include "Array2D.h"



int **Array2D(int n_rows, int n_columns)
{
    if(n_rows<=0 || n_columns<=0) return nullptr;
    int **Array = NewArray2D(n_rows, n_columns);
    int value=1;
    for(int i=0; i<n_rows; i++)
    {
        for(int j=0; j<n_columns; j++)
        {
            Array[i][j]=value;
            value++;
        }
    }
    return Array;

}

int **NewArray2D(int n_rows, int n_columns) {
    int **Array= new int *[n_rows];
    for(int i=0; i<n_rows; i++)
    {
        Array[i]= new int [n_columns];
    }
    return Array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i=0; i<n_rows; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}

void PrintArray2D(int **array, int n_rows, int n_columns)
{
    for(int i=0; i<n_rows; i++)
    {
        for(int j=0; j<n_columns; j++)
        {
            std::cout<<array[i][j];
        }
    }
}