#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAXSIZE 100
#define ERROR 0
#define F 0
#define OVERFLOW 0
#define OK 1
typedef char ElemType;
using namespace std;

// ջ
typedef struct SqStack //��ָ�� + ��ָ�� + ��С
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;

// ��ʼ��
stack InitStack(stack &s)
{
    s.base = new ElemType[MAXSIZE];
    if(!s.base) return OVERFLOW;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return OK;
}

// ѹջ
stack Push(stack &s,ElemType e)
{
    if(s.top - s.base == s.stacksize)
        return ERROR;
    *s.top++ = e;
    return OK;
}

// ��ջ
stack Pop(stack &s,ElemType e)
{
    if(s.base == s.top)
        return ERROR;
    e = *--s.top;
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
        s.top = NULL��
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
queue InitQueue(queue &q)
{
    q->base = ElemType[MAXSIZE];
    q->front = 0;
    q->rear  = 0;
}

// ����
queue Push(queue &q,ElemType e)
{
    if(q->front == MAXSIZE)
        return OVERFLOW;
    q->base[front++] = e;
    return OK;
}

// ����
queue Pop(queue &q,ElemType e)
{
    if(q->front == 0)
        return ERROR;
    for(int i = 0;i<q->front;i++){
        q->base[i] = q->base[i+1];
    }
    q->front--;
    return OK;
}

// �ж϶ӿ�
int QueueEmpty(queue q)
{
    if(q->front == 0)
        return OK
    return 0;
}

// ���ٶ���
int QueueDestroy(queue &q)
{
    free((*q)->front);
	free(*q);
	*q = NULL;

    return OK;
}

// ȡ���г���
int QueueGetLength(queue q)
{
    return q->front + 1;
}


int main(){
    return 0;
}