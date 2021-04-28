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

// 栈
typedef struct SqStack //顶指针 + 底指针 + 大小
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;

// 初始化
stack InitStack(stack &s)
{
    s.base = new ElemType[MAXSIZE];
    if(!s.base) return OVERFLOW;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return OK;
}

// 压栈
stack Push(stack &s,ElemType e)
{
    if(s.top - s.base == s.stacksize)
        return ERROR;
    *s.top++ = e;
    return OK;
}

// 出栈
stack Pop(stack &s,ElemType e)
{
    if(s.base == s.top)
        return ERROR;
    e = *--s.top;
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
int StackDestory(stack &s)
{
    if(s.base)
    {
        delete s.base;
        s.stacksize = 0;
        s.top = NULL；
    }
    return OK;
}

// 队列
typedef struct SqQueue
{

}queue;
// 初始化队列
queue InitQueue(queue q);
// 进队
queue Push(queue q);
// 出队
queue Pop(queue q);
// 判断队空
int QueueEmpty(queue q);
// 销毁队列
int QueueDestory(queue q);



int main(){
    return 0;
}