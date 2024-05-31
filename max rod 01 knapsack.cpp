#include<stdio.h>
int max(int a,int b){
    return(a>b)?a:b;
}
int cutRod(int prices[],int n){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int max_val=-1;
        for(int j=0;j<i;j++){
            max_val=max(max_val,prices[j]+dp[i-j-1]);
        }
        dp[i]=max_val;
    }
    return dp[n];
}
int main(){
	int prices[]={1,5,8,9,10,17,17,20};
    int n=sizeof(prices)/sizeof(prices[0]);
	int max_value=cutRod(prices,n);
	printf("Maximum obtainable value: %d\n",max_value);
	return 0;
}

