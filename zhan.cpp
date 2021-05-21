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

// ջ
typedef struct SqStack //��ָ�� + ��ָ�� + ��С
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;

// ��ʼ��
int InitStack(stack &s)
{
    s.base = new ElemType[MAXSIZE];
    if(!s.base) return OVERFLOW;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return OK;
}

// ѹջ
int Push(stack &s,ElemType e)
{
    if(s.top - s.base == s.stacksize)
        return ERROR;
    *s.top++ = e;
    return OK;
}

// ��ջ
int Pop(stack &s,ElemType *e)
{
    if(s.base == s.top)
        return ERROR;
    *e = *--s.top;
    return OK;
}

// ȡջ��Ԫ��
int StackGetTop(stack s,ElemType &e)
{
    if(s.top == s.base) return ERROR;
    e = *(s.top -1);
    return OK;
}

// �ж�ջ��
int StackEmpty(stack s)
{
    if(s.top == s.base) return OK;
    else return 0;
}

// ��˳��ջ�ĳ���
int StackLength(stack s)
{
    return s.top - s.base;
}

// ����ջ
int StackDestroy(stack &s)
{
    if(s.base)
    {
        delete s.base;
        s.stacksize = 0;
        s.top = NULL;
    }
    return OK;
}

// ����
typedef struct SqQueue
{
    ElemType *base;
    int front;
    int rear;
}queue;

// ��ʼ������
int InitQueue(queue &q)
{

    q.base = new ElemType[MAXSIZE];
    if(!q.base) exit(OVERFLOW);
    q.front = 0;
    q.rear  = 0;
    return OK;
}

// ����
int Push(queue &q,ElemType e)
{
    if((q.rear + 1)%MAXSIZE == q.front) 
        return ERROR;
    q.base[q.rear] = e;
    q.rear = (q.rear+1)%MAXSIZE;

	num++;
    return OK;
}

// ����
int Pop(queue &q,ElemType *e)
{
    if(q.front == q.rear)
        return ERROR;
    *e = q.base[q.front];
    q.front = (q.front + 1)%MAXSIZE;
    return OK;
}

// �ж϶ӿ�
int QueueEmpty(queue q)
{
    if(q.front == q.rear)
        return OK;
    return 0;
}

// ���ٶ���
int QueueDestroy(queue &q)
{
    if(q.base)
    {
        delete q.base;
        q.front = 0;
        q.rear = 0;
        q.base = NULL;
    }
    return OK;
}

// ȡ���г���
int QueueGetLength(queue q)
{
    return (q.rear - q.front + MAXSIZE)%MAXSIZE;
}

char getAZ()
{
	char c = char(97+rand()%26);
	// printf("%c\n",c);
	return c;
}

int main(){
    stack s;
    queue q;
	int i;
	char temp;

    InitStack(s);
    InitQueue(q);

    char a[MAXSIZE];
    for(i = 0;i<MAXSIZE;i++)
    {
        a[i] = getAZ();
		printf("%c  ",a[i]); 
		// ��ջ
        Push(s,a[i]);
    }
	printf("\n");

	for(i = 0;i<MAXSIZE;i++)
	{
		// ��ջ
		Pop(s,&temp);
		// �����
		Push(q,temp);

		// ������
		Pop(q,&temp);
		// �����
		Push(q,temp);
		// ������
		Pop(q,&temp);
		// �����
		Push(q,temp);
	}
	
	for(i = 0;i<MAXSIZE;i++)
	{
		// ������
		Pop(q,&temp);
		// ��ջ
        Push(s,a[i]);
	}

	for(i = 0;i<MAXSIZE;i++)
	{
		// ��ջ
		Pop(s,&temp);
		printf("%c  ",temp);
	}
	
	// printf("%d",StackLength(s));
	printf("\n���ӵĴ���Ϊ:%d\n",num);
	printf("��ͷ�±�Ϊ:%d\n",q.front);
    return 0;
}