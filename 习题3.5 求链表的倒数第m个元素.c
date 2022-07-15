/*�����ʱ��Ϳռ��϶������ܸ�Ч���㷨���ڲ��ı������ǰ���£�
����ʽ�洢�����Ա�ĵ�����m��>0����Ԫ�ء�*/

#include<stdio.h>
#define ERROR -1

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

/*����һ����СΪm�����飬������m�����ض�λ�����������*/
/*��������һ���������λ��k��λ�ã�������m��Ԫ�ص�λ��Ӧ��Ϊ[k-��m-1)],
����k+1��-m�����ǵ�һ��ѭ������Ϊm��ʵ��λ��Ϊ[(k+1)-m]%m,��Ϊ��k+1��%m*/
ElementType Find(List L, int m) {
    List* A = malloc(m * sizeof(List));
    /*��ʼ������*/
    for (int i = 0; i < m; i++)
        A[i] = NULL;
    if (!L) return ERROR;
    int rear = 0;
    while (L) {
        A[rear] = L;
        rear = (rear + 1) % m;
        L = L->Next;
    }
    if (A[rear] == NULL)
        return ERROR;
    return A[rear]->Data;
}

/*�ͷŽ��*/
void Free(List L) {
    List t;
    while (L) {
        t = L;
        L = t->Next;
        free(t);
    }
}


/*���Խ�һ����ջ��Ȼ���׳���ջ�еĵ�m��Ԫ�ؼ���*/
/*���ڲ�֪��ԭ�������е�Ԫ�أ���˶�ջ����������洢*/
typedef struct SNode *PtrToSNode;
struct SNode {
    List L; 
    PtrToSNode Next;
};

typedef PtrToSNode Stack;

/*����һ����ջ��ͷ���*/
Stack CreateStack() {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

/*�ж϶�ջ�Ƿ�Ϊ��*/
int IsEmpty(Stack S) {
    if (S->Next == NULL)
        return 1;
    else
        return 0;
}

/*���ջ�м���Ԫ��*/
void Push(Stack S, List L) {
    Stack T = CreateStack();
    T->L = L;
    T->Next = S->Next;
    S->Next = T;
    return ;
}

/*�Ӷ�ջ���׳�Ԫ��*/
List Pop(Stack S) {
    List L = NULL;
    Stack T = NULL;
   if (!IsEmpty(S)) {
       T = S->Next;
       L = T->L;
       S->Next = T->Next;
       free(T);
    }
   return L;
}

/*�ͷŶ�ջ������L��ռ�Ŀռ�*/
void Free(Stack S, List L) {
    /*�ͷŶ�ջ*/
    Stack TS = NULL;
    while (!IsEmpty(S)) {
        TS = S->Next;
        S->Next = TS->Next;
        free(TS);
    }
    free(S);

    /*�ͷ�������ռ�Ŀռ�*/
    List TL = NULL;
    while (L) {
        TL = L;
        L = L->Next;
        free(TL);
    }
    return;
}

ElementType Find(List L, int m) {
   List posit = L; /*�ݴ�Lͷ���*/
   int count = 0; /*��¼Ԫ�ص��ܸ���*/
   ElementType X = ERROR; /*��¼Ҫ���ص�Ԫ��*/
   Stack S = CreateStack();
   Stack Temp = S; /*�ݴ�Sͷ���*/
   /*��Ԫ�ؼ����ջ��*/
   while (L) {
       Push(S, L);
       L = L->Next;
       count++;
   }

   L = posit;

   /*Ԫ�ز���*/
   if (count < m) {
       Free(S, L);
       return ERROR;
   }

   if (count / 2 < m) {/*Ԫ���ں���*/
       /*�׳���ջ�еĵ�m��Ԫ��*/
       for (int i = 0; i < m; i++) {
           S = S->Next;
       }
       X = S->L->Data;
       S = Temp;
   }
   else {/*Ԫ����ǰ���*/
       for (int i = 1; i < m; i++) {
           L = L->Next;
       }
       X = L->Data;
       L = posit;
   }

   Free(S, L);
   return X;
}




int main() {

	return 0;
}