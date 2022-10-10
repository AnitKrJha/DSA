#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}
int main()
{
    int arr[] = {6, 5, 12, 2, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}