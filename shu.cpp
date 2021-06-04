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

void BiTreeIni(BiTree T)
{
    T->e = NULL;
    T->lchild = NULL;
    T->rchild = NULL;
}

// 
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
	T->e = NULL;
	T->lchild = NULL;
	T->rchild = NULL;

	if(ch == '(')
		T->lchild=BiTreeCreat3();
	else if(ch == ',' || ch == '??')
		T->rchild=BiTreeCreat3();
	else if(ch == ')')
		return NULL;
	else
	{
		
		T->e=ch;
		T->lchild=BiTreeCreat3();
	}
	
	return T;	
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

// 
void BiTreePrint(BiTree T)
{
    if(T != NULL)
    {
		printf("?§µ?");
        printf("%c ",T->e);
		printf("??");
        BiTreePrint(T->lchild);
        printf("???");
		BiTreePrint(T->rchild);
    }
}

char getAZ()
{
	return char(65+rand()%26);
}

int main()
{
    BiTree T;
	int h = 0;
	char a[] = {"A(B(D(,G)),C(E,F))"};
	char *t = a;
	
	// while(*t != '\0')
	// 	printf("%c  ",*t++);
    T = BiTreeCreat2();
	
    BiTreePrint(T);
	h = BiTreeHeight(T);
	printf("%d  ",h);
    return 0;
}