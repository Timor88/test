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
int StackDestory(stack &s)
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

}queue;
// ��ʼ������
queue InitQueue(queue q);
// ����
queue Push(queue q);
// ����
queue Pop(queue q);
// �ж϶ӿ�
int QueueEmpty(queue q);
// ���ٶ���
int QueueDestory(queue q);



int main(){
    return 0;
}