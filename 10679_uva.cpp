#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void print_array(int * array,int size){
	for ( int i=0;i<size;i++){
		printf("%d",array[i]);
	}
	printf("\n");
}

void suffix_array(char * pattern,int *array)
{
	int i=0,j=0;
	int len=strlen(pattern);
	while(i<len){
		if(i==j) {
		}
		else if(pattern[i]==pattern[j]){
			j++;
		}
		else{
			while(j>0){
				j=array[j-1];
				if(pattern[i]==pattern[j])break;
			}
			if (pattern[i]==pattern[j]) j++;
		}
		array[i]=j;
		i++;
	}
}
char checkKMP(char *str,char *pattern)
{
	int pat_len=strlen(pattern);
	char res='n';
	if(pat_len==0) return 'y';
	else if (pat_len==1) {
		int index=-1;
		for (int i=0;i< strlen(str);i++){
			if(pattern[0]==str[i]) return 'y';
		}
		return 'n';
	}
	int * array=new int[strlen(pattern)];
	suffix_array(pattern,array);
	int j=0;
	for (int i=0;i<strlen(str);i++){	
		if(str[i]==pattern[j])j++;
		else if (j>0){
			j=array[j-1];
		}
		if(j==pat_len){
		res='y';
		break;
		}
	}
	return res;
}
int main(int argc, char *argv[] ){
	int k, n;
	scanf("%d",&k);
	char S[100001];
	char q[1001];
	while(k--){
		scanf("%s",&S);
		scanf("%d",&n);
		while(n--){
			scanf("%s",&q);
			char res=checkKMP(S,q);
			printf("%c\n",res);
			
		}
	}

}
