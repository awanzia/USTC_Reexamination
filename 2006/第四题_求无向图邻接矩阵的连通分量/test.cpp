/*
 *2006年第四题：求由邻接矩阵存储的无向图的连通分量
 *邻接矩阵储存在abc.in文件中
 *abc.in内容如下：
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
 *在xyz.out文件中保存每个连通分量
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 10
bool visit[MAXNUM];

FILE *fp,*fpo;

//定义Graph结构体类型
typedef struct{
	char vexstr[MAXNUM];  //顶点数组
	int adjMatrix[MAXNUM][MAXNUM];  //邻接矩阵
	int vexnum;  //顶点数
}Graph;

Graph g;

void DFS( Graph *g , int u , int depth){  //u表示当前访问顶点
	visit[u]=true;  //标记顶点u为已访问
	fprintf( fpo , "%c" , g->vexstr[u] );  
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
	
	//初始化g的顶点数组
	fscanf( fp , "%s" , g.vexstr );

	//初始化g的顶点数
	g.vexnum=strlen(g.vexstr); 
	

	//初始化g的邻接矩阵
	for( int i=0 ; i<g.vexnum ; i++ ){
		for( int j=0 ; j<g.vexnum ; j++ ){
			fscanf( fp , "%d" , &g.adjMatrix[i][j] );
		}
	}

	//初始化visit数组
	for( i=0 ; i<g.vexnum ; i++ ){
		visit[i]=false;
	}
	
	DFSTraverse();

	fclose(fp);
	fclose(fpo);

	return 0;

}
