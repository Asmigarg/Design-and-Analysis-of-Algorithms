#include<stdio.h>
void recursiveActivitySelector(int s[],int f[],int i,int j){
    int m=i+1;
    while(m<j&&s[m]<f[i]){
        m=m+1;
    }
	if(m<j){
        printf("Activity %d: Start Time = %d, Finish Time = %d\n",m+1,s[m],f[m]);
        recursiveActivitySelector(s,f,m,j);
    }
}
int main(){
    int n;
	printf("Enter the number of activities: ");
    scanf("%d", &n);
	int start[n],finish[n];
    printf("Enter the start times and finish times for each activity:\n");
    for (int i=0;i<n;i++){
        printf("Activity %d: ",i+1);
        scanf("%d %d",&start[i],&finish[i]);
    }
    printf("Selected Activities:\n");
    printf("Activity 1: Start Time=%d,Finish Time=%d\n",start[0],finish[0]);
    recursiveActivitySelector(start,finish,0,n);
	return 0;
}

