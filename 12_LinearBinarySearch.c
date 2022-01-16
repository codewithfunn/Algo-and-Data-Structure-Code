#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int size, int element){
   
    int low, mid, high;
    low=0;
    high=size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

 
 
int main(){
    // Unsorted array for linear search
    // int arr[] = {1,2,3,4,5,32,42,1,42,23,45};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 5;
    // int searchIndex = linearSearch(arr,size,element);
    // printf("The element %d was found at index %d \n", element , searchIndex);

    // Sorted array for binary search
    int arr[] = {2,8,14,32,66,100,104,200,400};
    int size = sizeof(arr)/sizeof(int);
    int element = 104; 
    int searchIndex = binarySearch(arr,size,element);

    printf("The element %d was found at index %d \n",element,searchIndex);
    return 0 ;
}