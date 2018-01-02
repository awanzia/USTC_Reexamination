/*
 *2006年第二题：判断某年的某月有多少天
 *按abc.in文件中给出的格式[年,月]，判断该月有多少天
 *abc.in的内容为：
 *[1987,10]
 *[2005,02]
 *[2008,03]
  */

#include<stdio.h>
#include<stdlib.h>

//判断闰年的函数
int Leapyear(int year)
{
	if( ( ( year%4==0 )&&( year%100!=0 ) )||( year%400==0 ) )
		return 1;   //为闰年
	return 0;
}

int main()
{
	int i;
	int year,month;

	FILE *fp,*fpo;
	if( ( fp=fopen( "abc.in" , "r" ) ) == NULL ){
		printf("不能打开此文件!");
		exit(0);
	}
	fpo=fopen("xyz.out","w");
	
	int day[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	
	for(i=0;i<3;i++)
	{
		fscanf(fp,"[%d,%d]\n",&year,&month);  //格式后面必须要有\n,否则就原地踏步
		fprintf(fpo,"%d.%d has %d days\n",year,month,day[Leapyear(year)][month]);
	}

	return 0;
}