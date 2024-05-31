#include<stdio.h>
#include<limits.h>
int matrixChainOrder(int p[],int n){
    int m[n][n];
	for(int i=1;i<n;i++)
        m[i][i]=0;
		for(int L=2;L<n;L++){
        for(int i=1;i<n-L+1;i++){
            int j=i+L-1;
            m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
	return m[1][n-1];
}
int main(){
    int arr[]={30,35,15,5,10,20,25};
    int size=sizeof(arr)/sizeof(arr[0]);
	printf("Minimum number of multiplications needed: %d\n",matrixChainOrder(arr,size));
    return 0;
}

