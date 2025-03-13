#include<stdio.h>
#define MAXSIZE 20000

typedef struct{
	int num;
	int dp;
	int begin,end;
}num; 

num Num[MAXSIZE];

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
	int n,flag = 1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&Num[i].num);
		if(Num[i].num >= 0){
			flag = 0;
		}
	}
	Num[0].dp = Num[0].num;
	Num[0].end = Num[0].num;
	Num[0].begin = Num[0].num;
	
	for(int i=1;i<n;i++){
		Num[i].dp = max(Num[i-1].dp+Num[i].num,Num[i].num);
		if(Num[i-1].dp+Num[i].num >= Num[i].num){
			Num[i].end = Num[i].num;
			Num[i].begin = Num[i-1].begin;
		} else {
			Num[i].end = Num[i].num;
			Num[i].begin = Num[i].num;
		}
	}
	int max = -2147483648,pos;
	for(int i=0;i<n;i++){
		if(Num[i].dp > max){
			pos = i;
			max = Num[i].dp;
		}
	}
	if(flag == 0){
		int max = -2147483648,pos;
	    for(int i=0;i<n;i++){
		    if(Num[i].dp > max){
			pos = i;
			max = Num[i].dp;
		    }
	    }
		printf("%d %d %d",max,Num[pos].begin,Num[pos].end);
	} else {
		printf("0 %d %d",Num[0].num,Num[n-1].num);
	}
	
	return 0;
}
