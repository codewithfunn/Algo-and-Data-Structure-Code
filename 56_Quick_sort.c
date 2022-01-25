#include <stdio.h>
/*
    1. i=low
    2. j=high
    3. pivot=low
    4. i++ until element > pivot is found
    5. j-- until element <= pivot is found
    6. swap A[i] & A[j] and repeat A & 5 until (j<=i)
    7. swap pivot & A[j]

*/
void printArray(int *A,int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
}
int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low +1;
    int j = high;
    int temp;

    do{
        while(A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        // step 6 swap A[i] and A[j]  
        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
 
    }while(i < j);
    //step 7-> swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void QuickSort(int A[],int low , int high){

    int partitionIndex ;// Index of pivot after partition
    if(low < high){

        partitionIndex = partition(A,low,high);
        QuickSort( A, low, partitionIndex-1);
        QuickSort( A, partitionIndex+1, high);
    }
}
int main(){
    // Array declaration
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2i, 2, 13, 12, 3, 5j, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to patition return 3(ind)



    int n = sizeof(A)/sizeof(A[0]);
    // print Array before QuickSort
    printArray(A,n); 
    QuickSort(A,0,n-1);
    // print Array after QuickSort
    printArray(A,n);
    return 0 ;
}