#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1
typedef char ElemType;
using namespace std;

// ջ
typedef struct SqStack
{

}stack;

// ��ʼ��
stack InitStack(stack p);
// ѹջ
stack Push(stack p);
// ��ջ
stack Pop(stack p);
// �ж�ջ��
int StackEmpty(stack p);
// ����ջ
int StackDestory(stack p);

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