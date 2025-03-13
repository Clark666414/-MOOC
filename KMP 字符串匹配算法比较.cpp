#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 3000000

char s[MAXSIZE];
char string[MAXSIZE];

void getnext(char T[], int next[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while (T[i] != '\0'){
        if (j == -1 || T[i] == T[j]){
	     // i为后缀位置；j为前缀位置
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j]; //若字符不同，则j值回溯
        }
    }
}

int KMPindex(char S[ ], char T[ ]) {
    int i = 0, j=0, *next;
    next = (int *)malloc(sizeof(int)*(strlen(T)+1));
    getnext(T, next); //求next
    while ( S[i]!='\0'&& T[j]!='\0') {
        if (S [i] == T[j] ) {
            i++;
            j++ ;
        }else{
        //j回退到相应位置开始匹配，i不变
            (j == 0) ? i++ :( j = next[j]);
        }
    }
    free(next);
    if ( T[j] == '\0'){
    	 //匹配成功，返回匹配位置
        return i-j;
	}else{
		return -1;
	}
}
int main()
{
	scanf("%s",s);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",string);
		int ans = KMPindex(s,string);
		if(ans == -1){
			printf("Not Found\n");
		} else {
			printf("%s\n",s+ans);
		}
	}
	return 0;
}
