
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int mergeSort1(int arr[], int temp[],
               int left, int right);
int finalmerge(int arr[], int temp[],
          int left, int mid,
          int right);
 

int mergeSort(int arr[], int array_size)
{
    int* temp = (int*)malloc(sizeof(int) * array_size);
    return mergeSort1(arr, temp, 0,
                      array_size - 1);
}
 
int mergeSort1(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
       
        mid = (right + left) / 2;
 
        inv_count += mergeSort1(arr, temp, left, mid);
        inv_count += mergeSort1(arr, temp, mid + 1, right);
 
       
        inv_count += finalmerge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
int finalmerge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
   
    while (j <= right)
        temp[k++] = arr[j++];
 
    
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 

int main(int argv, char** args)
{
    int n, i=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf(" Number of inversions are %d \n",
           mergeSort(arr, n));

    return 0;
}
