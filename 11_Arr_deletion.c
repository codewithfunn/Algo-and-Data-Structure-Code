#include <stdio.h>
void display(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void indDeletion(int arr[], int size, int index){
    for (int i = index; i < size-1; i++)
    {
    /*  
    arr{7,8,12,27,88}, size=5, index=2
    i=2 it run -> i<(size-1)4
    1st..    
    arr[2]=arr[2+1];
    arr{7,8,27,27,88}

    2nd..    
    arr[3]=arr[3+1];
    arr{7,8,27,88,88}

    3rd..
    fail - > i<size-1
    */
        arr[i] = arr[i+1];
    }
    
}
int main(){
    int arr[100] = {7,8,12,27,88};
    int size=5, index=2;
    display(arr,size);
    indDeletion(arr,size,index);
    size-=1;
    display(arr,size);
    return 0 ;
}