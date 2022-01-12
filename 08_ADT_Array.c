#include <stdio.h>
#include <stdlib.h>
    struct MyArray
    {
        int total_size;
        int used_size;
        int *ptr;
    };
    void createArray(struct MyArray *a, int tSize , int uSize){
        // (*a).total_size = tSize;
        // (*a).used_size = uSize;
        // // int *ptr = (int *) malloc(totalSize*sizeof(int));// prototype
        // (*a).ptr = (int *) malloc(tSize * sizeof(int));

        // we can write the Above code as :-  
        a->total_size = tSize;
        a->used_size = uSize;
        a->ptr = (int *) malloc(tSize * sizeof(int));
    }
    
    void show(struct MyArray *a){
        for (int i = 0; i < a->used_size; i++)
        {
            printf("%d\n",(a->ptr)[i]);
        }
    }
    void setValue(struct MyArray *a){
        int n;
        for (int i = 0; i < a->used_size; i++)
        {
            printf("Enter element %d :: ", i );
            scanf("%d",&n);
            (a->ptr)[i]=n;
        }
    }
int main(){
    struct MyArray marks;
    createArray(&marks , 10,2);
    printf("We are running setValue now \n");
    setValue(&marks);
    printf("We are running Show func now \n");
    show(&marks);
    return 0 ;
}