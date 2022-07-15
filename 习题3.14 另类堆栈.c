#include<stdio.h>
#include<stdbool.h>
#define ERROR -1

typedef int ElementType;

typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode {
    ElementType* Data;  /* �洢Ԫ�ص����� */
    Position Top;       /* ջ��ָ��       */
    int MaxSize;        /* ��ջ�������   */
};
typedef PtrToSNode Stack;

/*�ж϶�ջ�Ƿ�Ϊ��*/
bool IsEmpty(Stack S) {
    if (S->Top == 0) {
        return true;
    }
    else
        return false;
}

/*�ж϶�ջ�Ƿ�����*/
bool IsFull(Stack S) {
    if (S->Top == S->MaxSize)
        return true;
    else return false;
}

/*��Ԫ�ؼ����ջ*/
bool Push(Stack S, ElementType X) {
    if (IsEmpty(S)) {
        printf("Stack Full");
        return false;
    }

    S->Data[S->Top] = X;
    S->Top++;
    return true;
}

/*��Ԫ�ص�����ջ*/
ElementType Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Stack Empty");
        return ERROR;
    }

    ElementType retu = S->Data[S->Top--];
    return retu;
}






int main() {


	return 0;

}