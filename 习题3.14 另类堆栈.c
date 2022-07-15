#include<stdio.h>
#include<stdbool.h>
#define ERROR -1

typedef int ElementType;

typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode {
    ElementType* Data;  /* ´æ´¢ÔªËØµÄÊı×é */
    Position Top;       /* Õ»¶¥Ö¸Õë       */
    int MaxSize;        /* ¶ÑÕ»×î´óÈİÁ¿   */
};
typedef PtrToSNode Stack;

/*ÅĞ¶Ï¶ÑÕ»ÊÇ·ñÎª¿Õ*/
bool IsEmpty(Stack S) {
    if (S->Top == 0) {
        return true;
    }
    else
        return false;
}

/*ÅĞ¶Ï¶ÑÕ»ÊÇ·ñÒÑÂú*/
bool IsFull(Stack S) {
    if (S->Top == S->MaxSize)
        return true;
    else return false;
}

/*½«ÔªËØ¼ÓÈë¶ÑÕ»*/
bool Push(Stack S, ElementType X) {
    if (IsEmpty(S)) {
        printf("Stack Full");
        return false;
    }

    S->Data[S->Top] = X;
    S->Top++;
    return true;
}

/*½«ÔªËØµ¯³ö¶ÑÕ»*/
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