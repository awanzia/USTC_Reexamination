/*
 *2006年第一题
 *矩阵的转置：从abc.in中读入int矩阵，将之转置后输出到文件xyz.out中
 *文件abc.in的内容为：
 *3 4
 *12 34 56 78
 *23 45 14 56
 *123 456 675 76
  */

#include<stdio.h>
#include<stdlib.h>

int main(){
	int m,n;
	int i,j;
	m = n = 0;
	i = j = 0;

	//定义一个二维动态数组
	int **mx;   

	//打开文件
	FILE *fp,*fpo;
	if( ( fp = fopen( "abc.in" , "r" ) ) == NULL ){
		printf("文件不存在!\n");
		exit(0);
	}
	fpo=fopen("xyz.out","w");

	//先读入m和n的值
	fscanf( fp , "%d %d" , &m , &n );
	
	//给二维数组分配动态内存
	mx = (int **)malloc( m*sizeof(int *) );
	for( i=0 ; i<m ; i++ )
		mx[i] = (int *)malloc( n*sizeof(int) );
	

	//从abc.in读入矩阵
	for( i=0 ; i<m ; i++)
		for( j=0 ; j<n ; j++ ){
			fscanf( fp , "%d" , &mx[i][j] );
		}

	//打印转置矩阵。先固定列，再按行打印。每打印一行，就打印一个回车。
	for( j=0 ; j<n ; j++ ){
		for( i=0 ; i<m ; i++ ){
			fprintf( fpo , "%d " , mx[i][j] );
		}
		fprintf( fpo , "\n" );
	}
		
	//关闭文件
	fclose(fp);
	fclose(fpo);

	//释放内存
	for( i=0 ; i<m ; i++ ){
		free( mx[i] );
	}
	free( mx );

	return 0;
	
}
