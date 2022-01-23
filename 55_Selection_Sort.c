#include <stdio.h>
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        printf(" %d ",A[i]);
    }
    printf("\n");
}
void selectionSort(int *A, int n){
    printf("Selection Sort is running!\n");
    int indexOfMin , temp ;
    for(int i=0; i<n-1; i++){
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}
int main(){
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    // Array defination
    int A[] = {3, 5, 2, 13, 12};    
    int n = sizeof(A)/sizeof(A[0]);
    // printArray before Selection Sort
    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
    // printArray after Selection Sort
    return 0 ;
}