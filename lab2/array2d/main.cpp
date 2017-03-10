//
// Created by bienking on 07.03.17.
//
#include "Array2D.h"

using namespace std;

int main()
{
    int n_rows, n_columns;
    cin>>n_rows>>n_columns;
    int **Array=Array2D(n_rows,n_columns);
    PrintArray2D(Array, n_rows, n_columns);
    DeleteArray2D(Array, n_rows, n_columns);
}