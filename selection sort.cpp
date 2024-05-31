#include<stdio.h>
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if (minIndex != i){
		int temp=arr[i];     
		arr[i]=arr[minIndex];     //swapping A[i] and A[min]
		arr[minIndex]=temp;
        }
    }
}
int main(){
    int n;
	printf("Enter the number of elements: ");
    scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
	printf("Original array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
	selectionSort(arr,n);
	printf("\nSorted array: ");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
	return 0;
}

