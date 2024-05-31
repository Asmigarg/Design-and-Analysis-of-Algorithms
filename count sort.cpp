#include<stdio.h>
#include<stdlib.h>
void countSort(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int *count=(int *)malloc((max+1)*sizeof(int));
    for (int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    int *output=(int *)malloc(n * sizeof(int));
    for (int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    free(count);
    free(output);
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={4,2,1,4,3,1,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr,n);
    countSort(arr,n);
    printf("Sorted array: ");
    printArray(arr,n);
    return 0;
}

