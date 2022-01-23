#include <stdio.h>

void printArray(int *A,int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
}
void bubbleSortAdaptive(int *A,int n){
    int temp;
    int isSorted=0;
    for (int i = 0; i < n-1; i++) // for Number of passes
    {
        printf("Working on the pass No %d\n",i+1);
        isSorted =1;
        for (int j = 0; j < (n-1-i); j++)// For comparison in each pass
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted =0;
            }
        }
        if(isSorted){
            printf("Array is already sorted\n");
            return;
        }
        
    }   
}

void bubbleSort(int *A,int n){
    int temp;
    for (int i = 0; i < n-1; i++) // for Number of passes
    {
        for (int j = 0; j < (n-1-i); j++)// For comparison in each pass
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }   
}
int main(){
    int A[] ={12,54,65,7,23,9};
    int A2[] ={1,5,6,8,9,11};
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A,n);// Printing the array before bubble sorting
    bubbleSortAdaptive(A,n);// Function to sort the array
    printArray(A,n);// Printing the array after bubble sorting

    return 0 ;
}