#include <stdio.h>

void binarySearch (int arr[], int size, int ele) {
    int start = 0, end = size-1;
    int mid=(start+end)/2;
    int step = 0;
   
    while(start <= end) {
        step++;
        if (arr[mid] == ele) {
            printf("The element %d is present at index %d\n", ele, mid);
            printf("The program was completed in %d steps", step);
            break;
        }
        else if (ele > arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = (start + end) / 2;
    }
}

int main() {
int arr[20], n, ele;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    binarySearch(arr, n, ele);
    return 0;
}

