#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAXSIZE 100
#define ERROR 0
#define F 0
// #define OVERFLOW 0
#define OK 1
typedef char ElemType;
using namespace std;
int num = 0;

// 定义
typedef struct HString 
{
    ElemType * e;
    int length;
}S;

// 判空
int SB(S s)
{
    int i = s.length == 0?1:0;
	return i;
}

// 输出
void SBPrint(S s)
{
    if(s.length == 0)
		printf("??\n");
	else
		printf("???\n");
}

// 初始化
void SInit(S &s)
{
    s.e = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    s.length = 0;
}

// 输出长度
int SLength(S &s)
{
	int i=0;
	// printf("%d\n",i);
	return i;
}

// 串赋值
void SCopy(S &s, char t[])
{   
    int i = 0;
    while(t[i] != '\0')
    {
		// printf("  %d  %d  %c\n",s.length,i,t[i]);
        s.e[i] = t[i];
		i++;
        s.length++; 
    }
	
}

//   
void SCmp(S s1, S s2)
{
    int i = 0;
    while(1)
    {
        ;
    }

}

// 
void SCat(S &s,S s1, S s2)
{
    int i = 0;
    int j = 0;
    while(i<s1.length)
    {
		// printf("%d:%c\n",i,s1.e[i]);
        s.e[i++] = s1.e[i];
        s.length++;	
    }

    j = i;
    i = 0;

    while(i<s2.length)
    {	
		// printf("%d:%c\n",i,s2.e[i]);
        s.e[j++] = s2.e[i++];
        s.length++;
    }
}

// 
void SSlice(S s,int start,int end)
{
	// char t[];
    while(start <= end)
	{
		printf("%c  ",s.e[start-1]);
		start++;
	}
	printf("\n");
		
}

// 
int SSearch(S s,S s1)
{
	int i = 0;
	int j = 0;
	while(i < s.length - s1.length)
	{
		while(s.e[i+j] == s1.e[j])
		{
			j++;
			if(j == s1.length)
				break;
			
		}
		i++;
		j = 0;
	}
	printf("子串在%d到%d\n",i+1,i+s1.length);
	return i+1;
}

// 
void SPrint(S s)
{
	int i = 0;
	while(i< s.length)
    {
        printf("%c",s.e[i++]);
    }
	printf("\n");
}

char getAZ()
{
	return char(65+rand()%26);
}

// 
void SDestory(){}

int main(){
	S s1;
	S s2;
	S s3;
	int i = 0;

	char a[100] = {'\0'};
	char b[100] = {'\0'};

	while(i<14)
	{
		a[i] = getAZ();
		i++;
	}
	i = 0;
	// printf("%s\n",a);

	while(i<10)
	{
		b[i] = getAZ();
		i++;
	}

	SInit(s1);
	SInit(s2);
	SInit(s3);

	SCopy(s1,a);
	SPrint(s1);


	SCopy(s2,b);
	SPrint(s2);
	
	SCat(s3,s1,s2);
	SPrint(s3);

	SSlice(s3,2,s3.length);

	SSearch(s3,s2);
	// printf("%d\n,",SSearch(s3,s2));
	
    return 0;
}
