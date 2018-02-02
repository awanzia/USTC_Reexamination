/*
 *2006������⣺�����ڽӾ���洢������ͼ����ͨ����
 *�ڽӾ��󴢴���abc.in�ļ���
 *abc.in�������£�
 *ABCDEFGH
 *0 1 0 0 0 0 1 1
 *1 0 0 0 0 0 0 1
 *0 0 0 0 0 0 0 0
 *0 0 0 0 1 1 0 0
 *0 0 0 1 0 1 0 0
 *0 0 0 1 1 0 0 0
 *1 0 0 0 0 0 0 1
 *1 1 0 0 0 0 1 0
 *
 *��xyz.out�ļ��б���ÿ����ͨ����
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 10
bool visit[MAXNUM];

FILE *fp,*fpo;

//����Graph�ṹ������
typedef struct{
	char vexstr[MAXNUM];  //��������
	int adjMatrix[MAXNUM][MAXNUM];  //�ڽӾ���
	int vexnum;  //������
}Graph;

Graph g;

void DFS( Graph *g , int u , int depth){  //u��ʾ��ǰ���ʶ���
	visit[u]=true;  //��Ƕ���uΪ�ѷ���
	fprintf( fpo , "%c" , g->vexstr[u] );  //��Q��Ϊʲô��������ܰ����е���ͨ�������
	for( int v=0 ; v<g->vexnum ; v++ ){
		if( visit[v]==false && g->adjMatrix[u][v]==1 ){
			DFS(g,v,depth+1);
		}
	}
}

void DFSTraverse(){
	for( int u=0 ; u<g.vexnum ; u++ ){
		if( visit[u]==false ){
			DFS(&g,u,1);
			fprintf( fpo , "\n" );
		}
	}
}

int main(){

	if( (fp=fopen( "abc.in" , "r" )) == NULL ){
		printf( "this file does not exist!\n" );
		exit(0);
	}
	fpo=fopen( "xyz.out" , "w" );
	
	//��ʼ��g�Ķ�������
	fscanf( fp , "%s" , g.vexstr );

	//��ʼ��g�Ķ�����
	g.vexnum=strlen(g.vexstr); 
	

	//��ʼ��g���ڽӾ���
	for( int i=0 ; i<g.vexnum ; i++ ){
		for( int j=0 ; j<g.vexnum ; j++ ){
			fscanf( fp , "%d" , &g.adjMatrix[i][j] );
		}
	}

	//��ʼ��visit����
	for( i=0 ; i<g.vexnum ; i++ ){
		visit[i]=false;
	}
	
	DFSTraverse();

	fclose(fp);
	fclose(fpo);

	return 0;

}