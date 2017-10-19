#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int lcs_search(char * s1, char *s2){
	int len_s1=strlen(s1);
	int len_s2=strlen(s2);
	if((len_s1==0) || (len_s2==0)) return 0;
	int ** matrix= new int*[len_s2];

	for (int i=0;i<len_s2;++i){
		matrix[i]=new int[len_s1];
	}

	for (int i=0;i<len_s2;i++){
		for(int j=0;j<len_s1;j++){
			int left_val=0;
			int top_val=0;
			int diag_up=0;
			if(j>=1)left_val=matrix[i][j-1];
			if(i>=1)top_val=matrix[i-1][j];
			if(i>=1 && j>=1) diag_up=matrix[i-1][j-1];
			if(s1[j]==s2[i]){
				matrix[i][j]=diag_up+1;
			}
			else{
				matrix[i][j]=max(left_val,top_val);
			}
		}
	}

	int ret_val=matrix[len_s2-1][len_s1-1];
	for (int i=0;i<len_s2;i++){
		delete [] matrix[i];
	}

	delete [] matrix;
	return ret_val;

}


int main(){
	char s1[1001];
	char s2[1001];
	while(gets(s1)){/// important to use gets here so that white spaces aren't consumed
		gets(s2);
		int res=lcs_search(s1,s2);
		printf("%d\n",res);
	}
	return 0;
}