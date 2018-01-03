/*
 *2006年第三题：
 *从abc.in文件中读入给出的标识符，判断哪些是合法的C语言标识符
 *并统计出其个数
 *abc.in内容：
 *a-b
 *_merlin
 *8fa
 *total
 *file_name
 *a3bo9
 *cd#ab
 *@vbase
 *W.S.Piter
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 9

int isLegal(const char str[]){
	int j;
	if( isalpha(str[0]) || str[0]=='_' ){
		for( j=1 ; j<strlen(str) ; j++ ){
			if( !( str[j]=='_' || isalpha(str[j]) || isdigit(str[j]) ) ){
				return 0;
			}
		}
		return 1;
	}else{
		return 0;  //首字符不是字母或者不是下划线
	}
}


int main(void){
	FILE *fp,*fpo;
	if( ( fp = fopen( "abc.in" , "r" ) ) == NULL ){
		printf( "文件不存在!" );
		exit(0);
	}
	fpo=fopen( "xyz.out" , "w" );
	
	char str[20];
	int i,count=0;

	for( i=0 ; i<MAXLINE ; i++ ){
		fscanf( fp , "%s\n" , str );
		if( isLegal(str) ){
			fprintf( fpo , "%s\n" , str );
			count++;
		}
		
	}

	fprintf( fpo , "一共有%d个标识符\n" , count );

	return 0;

}