#include<stdio.h>
#define MAXSIZE 200000
int num[MAXSIZE];
int dp[MAXSIZE];

int max(int a,int b)
{
	if(a > b){
		return a;
	} else {
		return b;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	dp[0] = num[0];
	for(int i=1;i<n;i++){
		dp[i] = max(num[i],dp[i-1]+num[i]);
	}
	int max = -1;
	for(int i=0;i<n;i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}
	printf("%d",max);
	
	return 0;
} 
