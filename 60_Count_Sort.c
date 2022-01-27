#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void printArray(int A[] , int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
}
// this function will give you the maximum element in array
int maximumElement(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
}
void countSort(int A[],int n){
    int i,j;
    // Find the maximum element in A
    int max = maximumElement(A,n);
    printf("the maximum element in the array is %d\n",max);
    // Create the count Array
    int* count = (int *)malloc((max+1)*sizeof(int));
    

    // Initalize the count array element to 0
    for(i=0; i<max+1; i++){
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for(i=0; i<n; i++){
        count[A[i]]= count[A[i]]+1;
        printf("count[A[%d]] ::  %d \n",A[i],count[A[i]]);
    }
    
    i=0; // counter for count array
    j=0; // counter for given array

    while(i<= max){
        if(count[i]>0){
            A[j] = i;
            count[i] = count[i] -1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    //        0  1  2   3  4   5  6
    int A[] ={9, 1, 4, 14, 4, 15, 6};
    int n = sizeof(A) / sizeof(A[0]);   
    // printing Array before count Sort
    printArray(A,n);
    // count Sort 
    countSort(A,n);
    //printing Array after count Sort
    printArray(A,n);
    return 0 ;
}