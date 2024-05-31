#include<stdio.h>
int linearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if target is not found
}
int main(){
    int size,target;
	printf("Enter the size of the array: ");
    scanf("%d",&size);
	int arr[size];
	printf("Enter the elements of the array:\n");
	for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
	printf("Enter the element to be searched: ");
    scanf("%d",&target);
	int result=linearSearch(arr,size,target);
	if(result !=-1) {
        printf("Element found at index: %d\n",result);
        printf("element found: %d",arr[result]);
    }else{
        printf("Element not found in the array.\n");
    }
	return 0;
}

