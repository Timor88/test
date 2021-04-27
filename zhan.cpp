#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1
typedef char ElemType;
using namespace std;

// 栈
typedef struct SqStack
{

}stack;

// 初始化
stack InitStack(stack p);
// 压栈
stack Push(stack p);
// 出栈
stack Pop(stack p);
// 判断栈空
int StackEmpty(stack p);
// 销毁栈
int StackDestory(stack p);

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