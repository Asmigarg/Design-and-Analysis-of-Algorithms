#include<stdio.h>
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
	int L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
		 i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort
void mergeSort(int arr[],int l,int r){
    if(l<r){
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m=l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        // Merge the sorted halves
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements:\n",n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // Perform merge sort
    mergeSort(arr,0,n-1);

    printf("Sorted array:\n");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}

