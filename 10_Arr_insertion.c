#include <stdio.h>
void display(int arr[] , int size){
    // Code for Traversal
    for (int i = 0; i < size; i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
/*
    arr[1,2,3,4,5];
    size = 5;
    index-2 -> value 7;
    for(int i=5-1; i>=2; i--){
        arr[4+1] = arr[4];
        // arr{1,2,3,4,5,5};
        
        arr[3+1] = arr[3];
        // arr{1,2,3,4,4,5};
        
        arr[2+1] = arr[2];
        // arr{1,2,3,3,4,5};

        // satement is false nd loop exist arr[1+1] = arr[1];
    }    
    arr[2] = value->7;
        // arr{1,2,7,3,4,5};

*/

int indInsertion(int arr[],int size, int element, int capacity, int index){
    // Code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main(){
    int arr[100]= {7,8,12,27,88};
    int size=5, element=45, index=3, capacity=100;
    display(arr,size);
    indInsertion(arr,size,element,capacity,index);
    size+=1;   
    display(arr,size);
    return 0 ;
}