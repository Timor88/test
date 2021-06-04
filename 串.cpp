#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define    OK    1
#define  ERROR   -1
#define  OVERFLOW  -3
#define   BIG    2
#define   EQUAL  0
#define   LITTLE  -2
#define   MAXSIZE 100
typedef char ElemType;
typedef    int Status;

typedef  struct
{
	char *ch;
	int length;
}HString;


//初始化字符串
Status StrAssign(HString &s)
{
	s.ch = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    s.length = 0;
	return OK;
}
// 串赋值
void SCopy(HString &s, char e[])
{   
    int i = 0;
    while(e[i] != '\0')
    {
        s.ch[i++] = e[i];
	    //printf("%c",e[i-1]);
        s.length++; 
    }
}

// 销毁串
Status ClearString(HString &S)
{
	if(S.ch)
	{
		free(S.ch);
		S.ch=NULL;
	}
	S.length=0;
	printf("销毁成功！！\n");
	return OK;
}
//求长度
int StrLength(HString S)
{
	return S.length;
}

//求子串（第pos个位置，长度为len的子串,SubS拿来装子串）
Status SubString(HString S,HString &SubS,int pos,int len)
{
	if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1)
		return ERROR;
	if(SubS.ch)
		free(SubS.ch);
	if(len==0)
	{
		SubS.ch=NULL;
		SubS.length=0;
	}
	else
	{
		SubS.ch=(char*)malloc(len*sizeof(char));
		for(int i=0;i<len;i++)
		{
			SubS.ch[i]=S.ch[pos-1];
			pos++;
		}
		SubS.length=len;
	}
	return OK;
}


//比较两个字串的大小
int StrCompare(HString S,HString H)
{
	int time;
	time=0;
	if(S.length>H.length)
		return BIG;
	if(S.length<H.length)
		return LITTLE;
	if(S.length==H.length)
	{
		for(int i=0;i<S.length;i++)
		{
			if(S.ch[i]>H.ch[i])
				return BIG;
			if(S.ch[i]<H.ch[i])
				return LITTLE;
			if(S.ch[i]==H.ch[i])
				time++;
		}
		if(time==S.length)
			return EQUAL;
	}
	
}

//求一个字符串在主串中的位置
int SubStringLocation(HString S,HString T)
{
	int i=0;
	int count = 0;
	HString SubS;
	SubS.ch=NULL;
	SubS.length=0;
	while(i<S.length-T.length+1)
	{
		SubString(S,SubS,i,T.length); 
		if(StrCompare(T,SubS)!=EQUAL)
		{
			count++;
			i++;
		}
	}
	
	printf("字符比较次数：%d\n",count);
	printf("字串位置在%d-%d\n",i,i+T.length-1);
	return i-SubS.length+2;
}

//连接两个字符串为一个字符串
void StringCat(HString &s,HString s1,HString s2)
{
	s.length = 0;
	int i = 0;
    int j = 0;
    while(i< s1.length-1)
    {
		// printf("%d:%c\n",i,s1.ch[i]);
        s.ch[i++] = s1.ch[i];
        s.length++; 
		
    }

    j = i;
    i = 0;

    while(i< s2.length-1)
    {	
		//printf("%d:%c\n",i,s2.ch[i]);
        s.ch[j++] = s2.ch[i++];
        s.length++; 
    }

	// printf("%d",s.length);
}
// 串输出
void SPrint(HString s)
{
	int i = 0;
	// printf("%d\n",s.length);
	while(i<s.length)
    {
        printf("%c",s.ch[i]);
		i++;
		// printf("%d\n",i);
    }
	printf("\n");
}



char getAZ()
{
	char c = char(65+rand()%26);
	// printf("%c\n",c);
	return c;
}

int main()
{
	int i = 0;
	int loc = 0;
	HString s1,s2,s3;
	StrAssign(s1);
	StrAssign(s2);
	StrAssign(s3);
	char s[100];   
	for (i = 0;i<10;i++)
	{
		s[i] = getAZ();
	}
	s[i+1] = '\0';
	SCopy(s1,s);
	
	for (i = 0;i<10;i++)
	{
		s[i] = getAZ();
	}
	s[i+1] = '\0';
	SCopy(s2,s);

	SCopy(s3,s);
	printf("s1:");
	SPrint(s1);
	printf("s2:");
	SPrint(s2);
	

	i = StrCompare(s1,s2);
	if (i == 2)
		printf("s1比s2大\n");
	else if(i == -2)
		printf("s1比s2小\n");
	else
		printf("s1与s2相等\n");
	
	StringCat(s3,s1,s2);
	printf("s3:");
	SPrint(s3);
	
	SubString(s2,s1,5,6);
	printf("s1:");
	SPrint(s1);

	SubStringLocation(s3,s1);

	// printf("%d",loc);
	ClearString(s1);
	ClearString(s3);
	ClearString(s2);
	return 0;
}
