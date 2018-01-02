/*
 *2006��ڶ��⣺�ж�ĳ���ĳ���ж�����
 *��abc.in�ļ��и����ĸ�ʽ[��,��]���жϸ����ж�����
 *abc.in������Ϊ��
 *[1987,10]
 *[2005,02]
 *[2008,03]
  */

#include<stdio.h>
#include<stdlib.h>

//�ж�����ĺ���
int Leapyear(int year)
{
	if( ( ( year%4==0 )&&( year%100!=0 ) )||( year%400==0 ) )
		return 1;   //Ϊ����
	return 0;
}

int main()
{
	int i;
	int year,month;

	FILE *fp,*fpo;
	if( ( fp=fopen( "abc.in" , "r" ) ) == NULL ){
		printf("���ܴ򿪴��ļ�!");
		exit(0);
	}
	fpo=fopen("xyz.out","w");
	
	int day[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	
	for(i=0;i<3;i++)
	{
		fscanf(fp,"[%d,%d]\n",&year,&month);  //��ʽ�������Ҫ��\n,�����ԭ��̤��
		fprintf(fpo,"%d.%d has %d days\n",year,month,day[Leapyear(year)][month]);
	}

	return 0;
}