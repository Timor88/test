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

// 栈
typedef struct SqStack //顶指针 + 底指针 + 大小
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;

// 初始化
int InitStack(stack &s)
{
    s.base = new ElemType[MAXSIZE];
    if(!s.base) return OVERFLOW;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return OK;
}

// 压栈
int Push(stack &s,ElemType e)
{
    if(s.top - s.base == s.stacksize)
        return ERROR;
    *s.top++ = e;
    return OK;
}

// 出栈
int Pop(stack &s,ElemType *e)
{
    if(s.base == s.top)
        return ERROR;
    *e = *--s.top;
    return OK;
}

// 取栈顶元素
int StackGetTop(stack s,ElemType &e)
{
    if(s.top == s.base) return ERROR;
    e = *(s.top -1);
    return OK;
}

// 判断栈空
int StackEmpty(stack s)
{
    if(s.top == s.base) return OK;
    else return 0;
}

// 求顺序栈的长度
int StackLength(stack s)
{
    return s.top - s.base;
}

// 销毁栈
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

// 队列
typedef struct SqQueue
{
    ElemType *base;
    int front;
    int rear;
}queue;

// 初始化队列
int InitQueue(queue &q)
{

    q.base = new ElemType[MAXSIZE];
    if(!q.base) exit(OVERFLOW);
    q.front = 0;
    q.rear  = 0;
    return OK;
}

// 进队
int Push(queue &q,ElemType e)
{
    if((q.rear + 1)%MAXSIZE == q.front) 
        return ERROR;
    q.base[q.rear] = e;
    q.rear = (q.rear+1)%MAXSIZE;

	num++;
    return OK;
}

// 出队
int Pop(queue &q,ElemType *e)
{
    if(q.front == q.rear)
        return ERROR;
    *e = q.base[q.front];
    q.front = (q.front + 1)%MAXSIZE;
    return OK;
}

// 判断队空
int QueueEmpty(queue q)
{
    if(q.front == q.rear)
        return OK;
    return 0;
}

// 销毁队列
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

// 取队列长度
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
		// 入栈
        Push(s,a[i]);
    }
	printf("\n");

	for(i = 0;i<MAXSIZE;i++)
	{
		// 出栈
		Pop(s,&temp);
		// 入队列
		Push(q,temp);

		// 出队列
		Pop(q,&temp);
		// 入队列
		Push(q,temp);
		// 出队列
		Pop(q,&temp);
		// 入队列
		Push(q,temp);
	}
	
	for(i = 0;i<MAXSIZE;i++)
	{
		// 出队列
		Pop(q,&temp);
		// 入栈
        Push(s,a[i]);
	}

	for(i = 0;i<MAXSIZE;i++)
	{
		// 出栈
		Pop(s,&temp);
		printf("%c  ",temp);
	}
	
	// printf("%d",StackLength(s));
	printf("\n进队的次数为:%d\n",num);
	printf("队头下标为:%d\n",q.front);
    return 0;
}