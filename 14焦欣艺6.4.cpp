
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct BiTNode{
	char data;
	int num;
	struct BiTNode *Lchild, *Rchild;
}BiTNode,*BiTree;

int count = 1;
void putNum(BiTree &T){   
	if (T != NULL){
		putNum(T->Lchild);
		putNum(T->Rchild);
		T->num = count;
		count++;
	}
}
 
void printTree(BiTree T,int nLayer){    
	if (T == NULL) return;
	printTree(T->Rchild,nLayer+1);
	for (int i = 0; i < nLayer; i++)
		printf(" ");
	printf("%c\n", T->data);     
	printTree(T->Lchild,nLayer+1);
}
 
void printTreeNum(BiTree T, int nLayer){    
	if (T == NULL) return;
	printTreeNum(T->Rchild, nLayer + 1);
	for (int i = 0; i < nLayer; i++)
		printf(" ");
	printf("%d\n", T->num);     
	printTreeNum(T->Lchild, nLayer + 1);
}
