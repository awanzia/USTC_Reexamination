/*
 *2006���һ��
 *�����ת�ã���abc.in�ж���int���󣬽�֮ת�ú�������ļ�xyz.out��
 *�ļ�abc.in������Ϊ��
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

	//����һ����ά��̬����
	int **mx;   

	//���ļ�
	FILE *fp,*fpo;
	if( ( fp = fopen( "abc.in" , "r" ) ) == NULL ){
		printf("�ļ�������!\n");
		exit(0);
	}
	fpo=fopen("xyz.out","w");

	//�ȶ���m��n��ֵ
	fscanf( fp , "%d %d" , &m , &n );
	
	//����ά������䶯̬�ڴ�
	mx = (int **)malloc( m*sizeof(int *) );
	for( i=0 ; i<m ; i++ )
		mx[i] = (int *)malloc( n*sizeof(int) );
	

	//��abc.in�������
	for( i=0 ; i<m ; i++)
		for( j=0 ; j<n ; j++ ){
			fscanf( fp , "%d" , &mx[i][j] );
		}

	//��ӡת�þ����ȹ̶��У��ٰ��д�ӡ��ÿ��ӡһ�У��ʹ�ӡһ���س���
	for( j=0 ; j<n ; j++ ){
		for( i=0 ; i<m ; i++ ){
			fprintf( fpo , "%d " , mx[i][j] );
		}
		fprintf( fpo , "\n" );
	}
		
	//�ر��ļ�
	fclose(fp);
	fclose(fpo);

	//�ͷ��ڴ�
	for( i=0 ; i<m ; i++ ){
		free( mx[i] );
	}
	free( mx );

	return 0;
	
}
