   
#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge1(int A[], int mid, int low, int high){
        int i, j, k, B[20];
        i = low;
        j=mid+1;
        k=low;
        
        while(i<=mid && j<=high){
            if(A[i]<A[j]){
                B[k] = A[i];
                k++,i++;
            }
            else{
                B[k] = A[j];
                k++,j++;
            }
        }

        while(i<= mid){
            B[k] = A[i];
            k++,i++;
        }
        while(j<=high){
            B[k] =A[j];
            k++,j++;
        }

        for (int i = low; i <= high; i++)
        {
            A[i] = B[i];
        }
        
    }
    // Recursive Approach 
    void MergeSort(int A[], int low, int high){
        int mid;
        if(low<high){
            mid = (low + high)/2;
            MergeSort(A, low, mid);
            MergeSort(A, mid+1, high);
            merge1(A, mid, low, high);
        }
    }

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 8, 7, 5, 4, 3, 2, 1, 20, 30  };
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A, n);
    MergeSort(A,0,n-1);
    printArray(A, n);
    return 0;
}
