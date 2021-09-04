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

typedef struct BiTNode
{
    struct BiTNode *lchild;
    char e;
    struct BiTNode *rchild;
}*BiTree;

// ???????
void BiTreePrint(BiTree T)
{
    if(T != NULL)
    {
		// printf("?§µ?");
        printf("%c ",T->e);
		// printf("??:");
        BiTreePrint(T->lchild);
        // printf("???");
		BiTreePrint(T->rchild);
    }
	else
		printf("???????????\n");
}

// ???????
void BiTreePrint2(BiTree T)
{
    if(T != NULL)
    {
		BiTreePrint(T->lchild);
		BiTreePrint(T->rchild);
        printf("%c ",T->e);

    }
	else
		printf("???????????\n");
}

// ???????
void BiTreePrint3(BiTree T)
{
    if(T != NULL)
    {
		BiTreePrint(T->lchild);
        printf("%c ",T->e);
		BiTreePrint(T->rchild);
    }
	else
		printf("???????????\n");
}

// ???????
void BiTreeIni(BiTree T)
{
    T->e = NULL;
    T->lchild = NULL;
    T->rchild = NULL;
}

char getAZ()
{
	return char(65+rand()%26);
}

// #
void BiTreeCreat(BiTree T)
{   
	char c;
	scanf("%c",&c);

	if (c=='#')   T=NULL;  	
	else
	{
		printf("11  ");
		T= new BiTNode;    
		T->e=c;
		BiTreeCreat(T->lchild);
		BiTreeCreat(T->rchild);
	}	

}

// 0
BiTree BiTreeCreat2()
{   
    
    char ch; 
    scanf("\n%c",&ch); 
    if (ch=='0') return NULL; 
    else { 
        BiTree T=(BiTNode*)malloc(sizeof(BiTNode)); 
        T->e=ch; 
        T->lchild=BiTreeCreat2();
        T->rchild=BiTreeCreat2();
        return T; 
    } 
} 
BiTree BiTreeCreat3()
{   
	char ch; 
    scanf("\n%c",&ch);
	// printf("%c \n",ch);

	BiTree T=(BiTNode*)malloc(sizeof(BiTNode)); 
	
	if(ch == '(')
	{
		T->lchild = BiTreeCreat3();
		T->rchild = BiTreeCreat3();
	}
	else if(ch == ',')
		T->rchild = BiTreeCreat3();
	else if(ch == ')')
		return T;
	else 
	{
		T->e = ch;
		T->lchild = BiTreeCreat3();
	}
	return T;

	// T->e = NULL;
	// T->lchild = NULL;
	// T->rchild = NULL;

} 

void BiTreeCreat4(BiTree T, char* str)
{
	BiTree St[MAXSIZE];
	int top = -1;
	BiTree p,b;
	char ch = *str;
	b = NULL;
	int k;
	while (ch != '\0')
	{
		switch (ch)
		{
		case'(':
			St[++top] = p;
			k = 1;
			break;
		case')':
			top--;
			break;
		case',':
			k = 2;
			break;
		default:
			p = (BiTree)malloc(sizeof(BiTNode));
			p->e = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
				break;
			}
		}
		ch = *(++str);
	}
}

// 
int BiTreeHeight(BiTree T)
{
	if(T == NULL)
		return -1;
	int LeftHeight = BiTreeHeight(T->lchild) + 1;
	int RightHeight = BiTreeHeight(T->rchild) + 1;

	return LeftHeight > RightHeight?LeftHeight:RightHeight;
}

// ??????
int BiTreeNodeNumber(BiTree T)
{
	int number = 0;
	if(T != NULL)
    {
        number ++;
        number += BiTreeNodeNumber(T->lchild);
		number += BiTreeNodeNumber(T->rchild);
    }
	// else
		// printf("???????????\n");

	return number;
}

// ????????
int BiTreeLeafNodeNumber(BiTree T)
{
	int number = 0;
	if(T == NULL)
		return 0;

	if(T->lchild == NULL && T->rchild == NULL)
		return 1;
	else 

	return number + BiTreeLeafNodeNumber(T->lchild) + BiTreeLeafNodeNumber(T->lchild);
}

// ??????
void BiTreeDes(BiTree T)
{	
	T->e = NULL;
	T->lchild = NULL;
	T->rchild = NULL;
	free(T);
}

// ?????????
int main()
{
    BiTree T;
	int h = 0;
	int n = 0;
	// char a[] = {"A(B(D(,G)),C(E,F))"};
	char a[] = {"A(B,c)"};
	char *t = a;
	// BiTreeIni(T);
	// while(*t != '\0')
	// 	printf("%c  ",*t++);
    T = BiTreeCreat3();
	
    BiTreePrint(T);
	h = BiTreeHeight(T);
	printf("?????????%d\n",h+1);
	n = BiTreeNodeNumber(T);
	printf("???????????%d\n",n);
	n = BiTreeLeafNodeNumber(T);
	printf("?????????????%d\n",n);

    return 0;
}
/* ?????
creat2??
print;
BiTreeLeafNodeNumber
BiTreeNodeNumber

*/